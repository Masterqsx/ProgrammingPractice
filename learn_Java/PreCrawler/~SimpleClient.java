import java.io.*;
import java.util.*;
import java.util.regex.*;
import org.apache.commons.logging.*;
import org.apache.commons.httpclient.*;
import org.apache.commons.httpclient.methods.*;


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
    neg = new String[]{"suck","terrible","awful","hideous","bad","boring","stupid","worst","stupid","waste","\\?","sad","sadly","ridicious","terribly","hard","worse","lack","too","poorly"};
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
  public void ReviewDownload(String input_url) throws Exception{
    review_buffer.delete(0,review_buffer.length());
    HttpClient httpclient = new HttpClient();
    HttpMethod getmethod = new GetMethod(input_url);
    int statusCode=0;
    for(int i=0;i<8;i++){
      try{
        statusCode = httpclient.executeMethod(getmethod);
        break;
      }
      catch(Exception e){
        if(i>=6){
          System.out.println("The link can not visit");
          getmethod.releaseConnection();
          return;
        }
        getmethod.releaseConnection();
       // Thread.sleep(500);
      }
    }
    if(statusCode>500){
      for(int i=0;i<20;i++){
        if(i>=10){
          System.out.println("The server is blocked");
          getmethod.releaseConnection();
          return;
        }
       // Thread.sleep(500);
        statusCode = httpclient.executeMethod(getmethod);
      }
    }
    BufferedReader reviewstream = new BufferedReader(new InputStreamReader(getmethod.getResponseBodyAsStream())); 
    String str = new String();
    String review_url = new String();
    Pattern p = Pattern.compile("<a href=\"(.*?)\".*target=.*>See all .*? customer reviews...</a>");
    while((str=reviewstream.readLine())!=null){
      Matcher m = p.matcher(str);
      if(m.find()){
        review_url = new String(m.group(1));
        break;  
      }
    }
    getmethod.releaseConnection();
    HttpClient httpclient1 = new HttpClient(); 
    HttpMethod getmethod1 = new GetMethod(review_url);
    for(int i=0;i<8;i++){
      try{
        statusCode = httpclient1.executeMethod(getmethod1);
        break;
      }
      catch(Exception e){
        if(i>=6){
          System.out.println("The link can not visit");
          getmethod1.releaseConnection();
          return;
        }

        //Thread.sleep(500);  
        getmethod1.releaseConnection();     
      }
    }
    if(statusCode>500){
      for(int i=0;i<20;i++){
        if(i>=10){
          System.out.println("The server is blocked1");
          getmethod1.releaseConnection();
          return;
        }
        getmethod1.releaseConnection();
        //Thread.sleep(500);
        statusCode = httpclient1.executeMethod(getmethod1);
      }
    }
    System.out.println(statusCode);
    reviewstream = new BufferedReader(new InputStreamReader(getmethod1.getResponseBodyAsStream()));
    Pattern p1 = Pattern.compile("<span class=\"a-size-base review-text\">(.*?)</span>");
    while((str=reviewstream.readLine())!=null){
      Matcher m = p1.matcher(str);
      if(m.find()){
        review_buffer.append(m.group(1));
        review_buffer.append("\n");
        review_buffer.append("\n");
     }
    }
    getmethod1.releaseConnection();
  }

};



public class SimpleClient{
  public static void main(String[] args) throws Exception {
    LinguisticAnalyzer analyzer = new LinguisticAnalyzer();
    analyzer.ReviewDownload("http://www.amazon.com/reviews/iframe?akid=AKIAI3OXGOGWKURY554Q&alinkCode=sp1&asin=0133943038&atag=smartbuy002-20&exp=2016-02-24T19%3A28%3A56Z&v=2&sig=fryIZJ%2FMLEmBNK2TwK%2F6%2FhDAY1qaOzh4JlxR0C1%2B%2FbA%3D");
    System.out.println(analyzer.SentimentAnalyzer());
  }
};
