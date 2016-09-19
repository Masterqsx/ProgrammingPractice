package gui;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import com.ECS.client.jax.Item;
import com.ECS.client.jax.Items;
import com.ECS.client.jax.ItemSearchResponse;

import spark.ModelAndView;
import spark.template.velocity.VelocityTemplateEngine;

import static spark.Spark.*;

public class App {
	static int num;
	static ArrayList<String> largeImageArray = new ArrayList(); 
	static ArrayList<String> priceArray      = new ArrayList();
	static ArrayList<String> titleArray      = new ArrayList();
	static ArrayList<String> brandArray      = new ArrayList();
	static ArrayList<String> descriptionArray= new ArrayList();
	static ArrayList<String> linkArray       = new ArrayList();
	
	public static void main(String[] args){
		staticFileLocation("/public");
		
		// initialize AWSRequst object
		AWSRequest requestObj = new AWSRequest();
		// initialize a list of SimpleClient
		ArrayList<SimpleClient> client=new ArrayList<SimpleClient>();
		for(int i=0;i<10;i++){
			  client.add(new SimpleClient(i,"http://www.amazon.com/gp/product/B017DT45R4/ref=s9_simh_gw_g229_i2_r?ie=UTF8&fpl=fresh&pf_rd_m=ATVPDKIKX0DER&pf_rd_s=desktop-3&pf_rd_r=0SKV60E8Q4H9G0QCTWJK&pf_rd_t=36701&pf_rd_p=2437869462&pf_rd_i=desktop"));
		}
		ArrayList<String> product = new ArrayList<String>();
		
		
		get("/", (request, response) -> {
			
            HashMap model = new HashMap();
            model.put("searchbox", "templates/searchbox.vtl" );
            return new ModelAndView(model, "templates/index.vtl");
          }, new VelocityTemplateEngine());
	    
        get("/product", (request, response) -> {	
            HashMap model = new HashMap();
            String searchkey = request.queryParams("searchkey");
            // specify what Amazon API should return
            requestObj.setRequest("All", searchkey, "Images,ItemAttributes,Offers");
            // make a request and store the retrieved response
            ItemSearchResponse result = requestObj.getResponse();
            // for all the items returned in the response, get all relevant info
            int i = 1;
            //get the resources
            descriptionArray.clear();
            largeImageArray.clear();
            priceArray.clear();
            titleArray.clear();
            brandArray.clear();
            linkArray.clear();
            //client.clear();
            for (Items itemList : result.getItems()) {
            	
            	for (Item item : itemList.getItem()) {
            		
            		//largeImageArray.add(item.getLargeImage().getURL());
             		//priceArray.add(item.getOfferSummary().getLowestNewPrice().getFormattedPrice());
             		//titleArray.add(item.getItemAttributes().getTitle());
             		//brandArray.add(item.getItemAttributes().getBrand());
            		try {
            			model.put("brand" + i, item.getItemAttributes().getBrand());
            			brandArray.add(item.getLargeImage().getURL());
            		} catch (Exception e) {
            			model.put("brand" + i, "Title : N/A");
            			brandArray.add("Title : N/A");
            		}
            		
            		try {
            			model.put("img" + i, item.getLargeImage().getURL() );
            			largeImageArray.add(item.getLargeImage().getURL());
            		} catch (Exception e) {
            			model.put("img" + i, "https://upload.wikimedia.org/wikipedia/commons/thumb/a/ac/No_image_available.svg/300px-No_image_available.svg.png");
            			largeImageArray.add("https://upload.wikimedia.org/wikipedia/commons/thumb/a/ac/No_image_available.svg/300px-No_image_available.svg.png");
            		}
            		
            		try {
            			model.put("title" + i, item.getItemAttributes().getTitle() );
            			titleArray.add(item.getItemAttributes().getTitle());
            		} catch (Exception e) {
                    	model.put("title" + i, "Title : N/A" );
                    	titleArray.add( "Title : N/A");
            		}
            		
                    try {
                    	model.put("price" + i, item.getOfferSummary().getLowestNewPrice().getFormattedPrice() );
                    	priceArray.add(item.getOfferSummary().getLowestNewPrice().getFormattedPrice());
                    } catch (Exception e) {
                    	model.put("price" + i, "Price : N/A" );
                    	priceArray.add( "Price : N/A");
                    }
                    try {
                    	model.put("amazonLink" + i, item.getItemLinks().getItemLink().get(0).getURL() );
                    	client.get(i-1).reset(new String(item.getItemLinks().getItemLink().get(0).getURL()));
                        //client.add(new SimpleClient(i-1,item.getItemLinks().getItemLink().get(0).getURL() ));
                    	linkArray.add(item.getItemLinks().getItemLink().get(0).getURL());                 	
                    	
                    } catch (Exception e) {
                    	model.put("amazonLink" + i, "/");
                    	linkArray.add( "/");
                    }
                    i++;
          	  }
            }
            
            model.put("keyword", searchkey );
            model.put("searchbox", "templates/searchbox.vtl" );
            model.put("list_grid_view", "templates/list_grid_view.vtl" );
            return new ModelAndView(model, "templates/product.vtl");
          }, new VelocityTemplateEngine());
    
			  
        get("/product/:name", (request, response) -> {
        	//use route patterns parameters to create different route 
    		request.params(":name");
    		
    		//get the URL of the web page
    		String path = request.url();
    		int len = path.length();
    		//get the parameters
    		int k =  Character.getNumericValue(path.charAt(len-1));
            
    		HashMap model = new HashMap();
            model.put("searchbox", "templates/searchbox.vtl" );
            if(k>10) System.out.println(path);
            client.get(k-1).run();
            //console test
            System.out.println(path);
    		System.out.println(k);
	        System.out.println(client.get(k-1).avgStar.get(0));
			System.out.println(client.get(k-1).avgStar.get(1));
			System.out.println(client.get(k-1).avgStar.get(2));
			System.out.println(client.get(k-1).reviews.get(0).star);//check
			System.out.println(client.get(k-1).imageSrc);//check
			System.out.println("******************************");
			
			//get the resources
			model.put("productTitle", titleArray.get(k-1));
    		model.put("brand", brandArray.get(k-1));
    		model.put("price", priceArray.get(k-1));
    		model.put("largeImage", largeImageArray.get(k-1));
    		model.put("priceHistoryImage",client.get(k-1).imageSrc.equals("no image")?"https://upload.wikimedia.org/wikipedia/commons/thumb/a/ac/No_image_available.svg/300px-No_image_available.svg.png":client.get(k-1).imageSrc);
    		
    		
    		for(int n=0; n < 5; n++){
    			model.put("R1star" + n,"fa fa-star"+client.get(k-1).avgStar.get(0).get(n));
    			model.put("R2star" + n,"fa fa-star"+client.get(k-1).avgStar.get(1).get(n));
    			model.put("R3star" + n,"fa fa-star"+client.get(k-1).avgStar.get(2).get(n));
    		}
    		
    		for(int m=1; m < client.get(k-1).reviews.size(); m++){
    			for(int i=0; i<5; i++){
    				model.put("reviewStar"+m+i,"fa fa-star" + client.get(k-1).reviews.get(m).star.get(i));
    				//System.out.println(m+"reviewStar"+i);
    			}	
    			model.put("reviewTitle"+m, client.get(k-1).reviews.get(m).title);
    			model.put("reviewContent"+m, client.get(k-1).reviews.get(m).review);
    		}
    		
    		model.put("highestPrice", client.get(k-1).pri.high_price==null?"-":client.get(k-1).pri.high_price);
    		model.put("highestTime", client.get(k-1).pri.high_time==null? "-":client.get(k-1).pri.high_time);
    		model.put("lowestPrice", client.get(k-1).pri.low_price==null? "-":client.get(k-1).pri.low_price);
    		model.put("lowestTime", client.get(k-1).pri.low_time==null? "-":client.get(k-1).pri.low_time);
    		model.put("averagePrice", client.get(k-1).pri.average==null? "-":client.get(k-1).pri.average);
    		model.put("amazonLink", linkArray.get(k-1));
    		//arrange the template
            model.put("product_detail_view", "templates/product_detail_view.vtl" );
            return new ModelAndView(model, "templates/product_detail.vtl");
          }, new VelocityTemplateEngine());
	}
}
	
	
	
	
