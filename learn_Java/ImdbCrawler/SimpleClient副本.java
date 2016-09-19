import java.io.*;
import java.util.*;
import java.util.regex.*;
import org.apache.commons.logging.*;
import org.jsoup.*;
import org.jsoup.nodes.*;
import org.jsoup.select.*;

import com.gargoylesoftware.htmlunit.*;
import com.gargoylesoftware.htmlunit.html.*;
import com.gargoylesoftware.htmlunit.javascript.background.JavaScriptJobManager;





class LinguisticAnalyzer{
  private StringBuffer review_buffer;
  private String analysis_result;
  private HashMap<String,Integer> word_map;
  private String[] pos;
  private String[] neg;  
  public LinguisticAnalyzer(){
    review_buffer = new StringBuffer();
    analysis_result = new String("Neutral");
    pos = new String[]{"dazzling","brilliant","phenomenal","excellent","fantastic","gripping","mesmerizing","riveting","spectacular","cool","awesome","thrilling","badass","moving","exciting","good","wonderful","not bad","nice","fantastic","love","useful","well explained","worth","worthy","great"};
    neg = new String[]{"suck","terrible","awful","hideous","bad","boring","stupid","worst","stupid","waste","\\?","sad","sadly","ridicious","terribly","hard","worse","lack","poorly"};
    word_map = new HashMap<String,Integer>();
    for(String word:pos){
      word_map.put(word,1);
    }
    for(String word:neg){
      word_map.put(word,-1);
    }
  }
  
  public String GetReview(){
    String review = new String(review_buffer);
    return review;
  }

  public String GetResult(){
    return analysis_result;
  }

  public int SentimentAnalyzer(){
    String review = new String(review_buffer);
    int count=0; 
    for(String word:pos){
      Pattern p = Pattern.compile(word,Pattern.CASE_INSENSITIVE);
      Matcher m = p.matcher(review);
      while(m.find())
        count++;
    }
    for(String word:neg){
      Pattern p = Pattern.compile(word,Pattern.CASE_INSENSITIVE);
      Matcher m = p.matcher(review);
      while(m.find())
        count--;
    }
    return count;
  }
  
  public void PriceLocator(String input_url,int index) throws Exception{
	  java.util.logging.Logger.getLogger("com.gargoylesoftware.htmlunit").setLevel(java.util.logging.Level.OFF);
	  java.util.logging.Logger.getLogger("org.apache.http").setLevel(java.util.logging.Level.OFF);
	  final WebClient webclient=new WebClient(BrowserVersion.BEST_SUPPORTED); 
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
		  Thread.sleep(200);
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
  
  public void PriceImage(int index) throws Exception{
	  java.util.logging.Logger.getLogger("com.gargoylesoftware.htmlunit").setLevel(java.util.logging.Level.OFF);
	  java.util.logging.Logger.getLogger("org.apache.http").setLevel(java.util.logging.Level.OFF);
	  final WebClient webclient=new WebClient(BrowserVersion.BEST_SUPPORTED);
	  webclient.getOptions().setCssEnabled(false);
	  webclient.getOptions().setThrowExceptionOnScriptError(false);
	  webclient.getOptions().setThrowExceptionOnFailingStatusCode(false);
	  final HtmlPage page2=webclient.getPage("file:./SearchResult_"+Integer.toString(index)+".html");
	  final HtmlImage price_history=(HtmlImage)page2.getFirstByXPath("//*[@id='summary_chart']");
	  File imageFile = new File("Price_"+Integer.toString(index)+".jpg");
      if(!imageFile.exists()){
    	  imageFile.createNewFile();
      }
      price_history.saveAs(imageFile);
      webclient.close();
  }

  public void
 ReviewParser(String input_url) throws Exception{
	  Document doc = Jsoup.connect(input_url).data("query", "Java")
			  .userAgent("Mozilla")
			  .cookie("auth", "token")
			  .timeout(3000)
			  .post();
	  Element review_content = doc.getElementById("tn15content");
	  Elements list = review_content.select("div>div,p");
	  File f = new File("review.html");
	  if (!f.exists()) {
		    f.createNewFile();
	  }
	  FileWriter fw = new FileWriter(f);
	  BufferedWriter bw = new BufferedWriter(fw);

	  
	  for(Element head:list){
		  bw.write(head.select("div,p:not(:has(a))").html());
	  }
	  bw.close();
  }

  public ArrayList<Float> StarLocator(String input_url) throws Exception{
	  Document doc = Jsoup.connect(input_url).data("query", "Java")
			  .userAgent("Chrome")
			  .cookie("auth", "token")
			  .timeout(3000)
			  .post();
	  Element WholeReview = doc.getElementById("revMHRL");
	  Element RecentReview = doc.getElementById("revMRRL");
	  Elements StarRating = WholeReview.select("span.a-icon-alt");
	  float avg=0;
	  int count=0;
	  for(Element star:StarRating){
		  Pattern p=Pattern.compile("([0-9.]*) out of");
		  Matcher m=p.matcher(star.text());
		 
		  if(m.find()){
			  avg+=Float.parseFloat(new String(m.group(1)));
			  count++;
		  }
	  }
	  ArrayList<Float> avgStar=new ArrayList<Float>();
	  avgStar.add(avg/count);
	  StarRating = RecentReview.select("span.a-icon-alt");
	  for(Element star:StarRating){
		  Pattern p=Pattern.compile("([0-9.]*) out of");
		  Matcher m=p.matcher(star.text());
		 
		  if(m.find()){
			  avg+=Float.parseFloat(new String(m.group(1)));
			  count++;
		  }
	  }
	  avgStar.add(avg/count);
	  return avgStar;
  }
};




public class SimpleClient{
  public static void main(String[] args) throws Exception {
    LinguisticAnalyzer analyzer = new LinguisticAnalyzer();
    analyzer.PriceLocator("http://www.amazon.com/Lodge-Pre-Seasoned-Cast-Iron-Skillet-10-25-inch/dp/B00006JSUA/ref=sr_1_2?ie=UTF8&qid=1459823892&sr=8-2&keywords=lodge",0);
    analyzer.PriceImage(0);
    ArrayList<Float> avgStar=new ArrayList<Float>(analyzer.StarLocator("http://www.amazon.com/Lodge-Pre-Seasoned-Cast-Iron-Skillet-10-25-inch/dp/B00006JSUA/ref=sr_1_2?ie=UTF8&qid=1459823892&sr=8-2&keywords=lodge"));
    System.out.println(avgStar.get(0));
    System.out.println(avgStar.get(1));
  }
};
