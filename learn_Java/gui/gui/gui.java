package gui;

import java.util.HashMap;

import com.ECS.client.jax.Item;
import com.ECS.client.jax.Items;
import com.ECS.client.jax.ItemSearchResponse;

import spark.ModelAndView;
import spark.template.velocity.VelocityTemplateEngine;

import static spark.Spark.*;

public class App {
	public static void main(String[] args) {
		staticFileLocation("/public");
		// initialize AWSRequst object
		AWSRequest requestObj = new AWSRequest();
		
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
            int j=0;
            for (Items itemList : result.getItems()) {
            	j++;
            	for (Item item : itemList.getItem()) {
            		
            		try {
            			model.put("img" + i, item.getLargeImage().getURL() );
            		} catch (Exception e) {
            			model.put("img" + i, "https://upload.wikimedia.org/wikipedia/commons/thumb/a/ac/No_image_available.svg/300px-No_image_available.svg.png");
            		}
            		
            		try {
            			model.put("title" + i, item.getItemAttributes().getTitle() );
            		} catch (Exception e) {
                    	model.put("title" + i, "Title : N/A" );
            		}
            		
                    try {
                    	model.put("price" + i, item.getOfferSummary().getLowestNewPrice().getFormattedPrice() );
                    } catch (Exception e) {
                    	model.put("price" + i, "Price : N/A" );
                    }
                    try {
                    	model.put("amazonlink" + i, item.getItemLinks().getItemLink().get(0).getURL() );
                    } catch (Exception e) {
                    	model.put("amazonlink" + i, "/");
                    }
                    i++;
            	}
            }
            System.out.print(i);
            System.out.print("\n");
            System.out.print(j);
            model.put("keyword", searchkey );
            model.put("searchbox", "templates/searchbox.vtl" );
            model.put("list_grid_view", "templates/list_grid_view.vtl" );
            return new ModelAndView(model, "templates/product.vtl");
          }, new VelocityTemplateEngine());
        
        get("/detail1", (request, response) -> {
            HashMap model = new HashMap();
            model.put("searchbox", "templates/searchbox.vtl" );
            model.put("product_detail_view", "templates/product_detail_view.vtl" );
            return new ModelAndView(model, "templates/product_detail.vtl");
          }, new VelocityTemplateEngine());
	}
}
	
	
	
	
