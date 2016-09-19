import java.io.*;
import java.util.*;
import java.util.regex.*;
import org.jsoup.*;
import org.jsoup.nodes.*;
import org.jsoup.select.*;

import com.gargoylesoftware.htmlunit.*;
import com.gargoylesoftware.htmlunit.html.*;

class reviewFrame{
	public float star;
	public String title;
	public String review;
	public reviewFrame(){
		star=(float)-1;
	}
	public reviewFrame(String rev){
		star=(float)-1;
		review=new String(rev);
	}
};
class priceFrame{
	public String high_price;
	public String high_time;
	public String low_price;
	public String low_time;
	public String average;
};


class LinguisticAnalyzer{

  public int index;
  public LinguisticAnalyzer(int i){
	  index=i;
  }

  public void PriceLocator(String input_url) throws Exception{
	  java.util.logging.Logger.getLogger("com.gargoylesoftware.htmlunit").setLevel(java.util.logging.Level.OFF);
	  java.util.logging.Logger.getLogger("org.apache.http").setLevel(java.util.logging.Level.OFF);
	  final WebClient webclient=new WebClient(BrowserVersion.CHROME); 
	  webclient.getOptions().setJavaScriptEnabled(false);
	  webclient.getOptions().setCssEnabled(false);
	  webclient.getOptions().setThrowExceptionOnScriptError(false);
	  webclient.getOptions().setThrowExceptionOnFailingStatusCode(false);
	  final HtmlPage page1=webclient.getPage("http://camelcamelcamel.com/");
	  final HtmlForm form=page1.getFirstByXPath("//form[@action='/search']");
	  final HtmlSubmitInput button = form.getFirstByXPath("//input[@id='searchbutton']");
	  final HtmlTextInput textField = form.getFirstByXPath("//input[@id='sq']");
	  textField.setValueAttribute(input_url);
	  WebWindow window = page1.getEnclosingWindow();
	  button.click();
	  while(window.getEnclosedPage() == page1) {
		  Thread.sleep(100);
	  }
	  final HtmlPage page2 = (HtmlPage) window.getEnclosedPage();
	  File f=new File("SearchResult_"+Integer.toString(index)+".html");
	  if(!f.exists()){
		  f.createNewFile();
	  }
	  FileWriter fw = new FileWriter(f);
	  BufferedWriter b = new BufferedWriter(fw);
	  b.write(page2.getWebResponse().getContentAsString());
	  b.close();
	  webclient.close();
  }

  public String PriceImage(priceFrame pri) throws Exception{
	  java.util.logging.Logger.getLogger("com.gargoylesoftware.htmlunit").setLevel(java.util.logging.Level.OFF);
	  java.util.logging.Logger.getLogger("org.apache.http").setLevel(java.util.logging.Level.OFF);
	  final WebClient webclient=new WebClient(BrowserVersion.CHROME);
	  webclient.getOptions().setCssEnabled(false);
	  webclient.getOptions().setThrowExceptionOnScriptError(false);
	  webclient.getOptions().setThrowExceptionOnFailingStatusCode(false);
	  final HtmlPage page2=webclient.getPage("file:./SearchResult_"+Integer.toString(index)+".html");
	  final HtmlImage price_history=(HtmlImage)page2.getFirstByXPath("//*[@id='summary_chart']");
	  final HtmlTable price_table=(HtmlTable)page2.getFirstByXPath("//table[@class='product_pane']");
	  for (final HtmlTableRow row : price_table.getRows()) {
		  if(row.getCell(0).asText().matches("Highest.*")){
			  pri.high_price=new String(row.getCell(1).asText());
			  pri.high_time=new String(row.getCell(2).asText());		  
		  }
		  if(row.getCell(0).asText().matches("Lowest.*")){
			  pri.low_price=new String(row.getCell(1).asText());
			  pri.low_time=new String(row.getCell(2).asText());		  
		  }
		  if(row.getCell(0).asText().matches("Average.*")){
			  pri.average=new String(row.getCell(1).asText());		  
		  }
		}
	  String src;
	  try{
		  src = new String(price_history.getSrcAttribute());
	  }
	  catch(Exception e){
		  src = null;
	  }
      webclient.close();
      return src;
  }

  public ArrayList<reviewFrame> ReviewParser(String input_url) throws Exception{
	  ArrayList<reviewFrame> rev=new ArrayList<reviewFrame>();
	  ArrayList<Float> stars=new ArrayList<Float>();
	  ArrayList<String> titles=new ArrayList<String>();
	  Document doc = Jsoup.connect(input_url).data("query", "Java")
			  .userAgent("Chrome")
			  .cookie("auth", "token")
			  .timeout(3000)
			  .post();
	  Element review_content = doc.getElementById("revMHRL");
	  try{
		  Elements reviews = review_content.select("div[class=a-row a-spacing-small]>div[class=a-section]");
		  Elements starratings = review_content.select("span.a-icon-alt");
		  Elements reviewtitle = review_content.select("span[class=a-size-base a-text-bold]");
		  Pattern p=Pattern.compile("([0-9.]*) out of");
		  for(Element star:starratings){	  
			  Matcher m=p.matcher(star.text());	 
			  if(m.find()){
				  stars.add(Float.parseFloat(new String(m.group(1))));
			  }
		  }
		  for(Element title:reviewtitle){
			  titles.add(title.text());
		  }
		  for(Element head:reviews){
			  Elements more=head.select("span.a-declarative");
			  if(more.hasText()){
				  p=Pattern.compile("[{]\"rest\":\" (.*)\"[}]");
				  Matcher m=p.matcher(more.first().attr("data-columnbalancing-showfullreview"));
				  if(m.find()){
					  rev.add(new reviewFrame(head.text()+m.group(1)));
				  }
			  }
			  else{
				  rev.add(new reviewFrame(head.text()));
			  }
		  }
		  for(int i=0;i<rev.size();i++){
			  rev.get(i).star=stars.get(i);
			  rev.get(i).title=new String(titles.get(i));
		  }
	  }
	  catch(Exception e){
		  rev.add(new reviewFrame());
	  }
	  return rev;
  }

  public ArrayList<Float> StarLocator(String input_url) throws Exception{
	  Document doc = Jsoup.connect(input_url).data("query", "Java")
			  .userAgent("Chrome")
			  .cookie("auth", "token")
			  .timeout(3000)
			  .post();
	  Element WholeReview = doc.getElementById("revMHRL");
	  Element RecentReview = doc.getElementById("revMRRL");
	  Element Introduction = doc.getElementById("centerCol");
	  Elements StarRating;
	  float avg=0;
	  int count=0;
	  Pattern p=Pattern.compile("([0-9.]*) out of");
	  ArrayList<Float> avgStar=new ArrayList<Float>();
	  try{
		  StarRating = WholeReview.select("span.a-icon-alt");
		  for(Element star:StarRating){	  
			  Matcher m=p.matcher(star.text());	 
			  if(m.find()){
				  avg+=Float.parseFloat(new String(m.group(1)));
				  count++;
			  }
		  }
		  avgStar.add(avg/count);
		  
	  }
	  catch (Exception e){
		  avgStar.add((float)-1);
	  }
	  
	  try{
		  StarRating = RecentReview.select("span.a-icon-alt");
		  for(Element star:StarRating){
			  Matcher m=p.matcher(star.text());	 
			  if(m.find()){
				  avg+=Float.parseFloat(new String(m.group(1)));
				  count++;
			  }
		  }
		  avgStar.add(avg/count);
	  }
	  catch(Exception e){
		  avgStar.add((float) -1);
	  }
	  
	  
	  Elements Star; 
	  try{
		  Star = Introduction.select("span.a-icon-alt");
	  
		  Matcher m=p.matcher(Star.first().text());
	  	  if(m.find()){
		    avgStar.add(Float.parseFloat(new String(m.group(1))));
	      }
	      else{
		    avgStar.add(new Float(5.0));
	      }
	  }
	  catch(Exception e){
		  avgStar.add((float) -1);
	  }
	  return avgStar;
  }
};




public class SimpleClient implements Runnable{
  private int index;
  public ArrayList<Float> avgStar;
  public String imageSrc;
  public String url;
  public ArrayList<reviewFrame> reviews;
  public priceFrame pri;
  public SimpleClient(int i,String input_url){
	  index=i;
	  url=new String(input_url);
	  pri=new priceFrame();
  }
  public void run(){
	  LinguisticAnalyzer analyzer = new LinguisticAnalyzer(index);
	  try {
		analyzer.PriceLocator(url);
	} catch (Exception e) {
		e.printStackTrace();
	}
	  try {
		imageSrc=new String(analyzer.PriceImage(pri));
	} catch (Exception e) {
		e.printStackTrace();
	}
	  try{
		reviews = new ArrayList<reviewFrame>(analyzer.ReviewParser(url));
	} catch (Exception e) {
			e.printStackTrace();
	}
	try {
	  avgStar = new ArrayList<Float>(analyzer.StarLocator(url));
	} catch (Exception e) {
		e.printStackTrace();
	}
  }
  public static void main(String[] args) throws Exception {
	  long startTime=System.currentTimeMillis();
	  ArrayList<Thread> ThreadList=new ArrayList<Thread>();
	  ArrayList<SimpleClient> client=new ArrayList<SimpleClient>();
	  for(int i=0;i<1;i++){
		  client.add(new SimpleClient(i,"http://www.amazon.com/gp/product/B0035WSYS0/ref=s9_simh_gw_g241_i4_r?ie=UTF8&fpl=fresh&pf_rd_m=ATVPDKIKX0DER&pf_rd_s=desktop-2&pf_rd_r=0Q7V3NWDEY1S8H42H39N&pf_rd_t=36701&pf_rd_p=2437869762&pf_rd_i=desktop"));
		  ThreadList.add(new Thread(client.get(i),Integer.toString(i)));
		  ThreadList.get(i).start();
	  }
	  for(int i=0;i<1;i++){
		  ThreadList.get(i).join();
		  System.out.println(client.get(i).avgStar.get(0));
		  System.out.println(client.get(i).avgStar.get(1));
		  System.out.println(client.get(i).avgStar.get(2));
		  System.out.println(client.get(i).reviews.get(0).title);
		  System.out.println(client.get(i).imageSrc);
	  }
	  long endTime=System.currentTimeMillis();
	  System.out.println("Running time = "+Long.toString(endTime-startTime)+" ms");
  }
};
