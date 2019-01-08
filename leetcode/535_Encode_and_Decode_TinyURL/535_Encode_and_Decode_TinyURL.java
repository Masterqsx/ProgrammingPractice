public class Codec {
    
    Map<Integer, String> store = new HashMap<>();

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        int hash = longUrl.hashCode();
        store.put(hash, longUrl);
        return new Integer(hash).toString();
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return store.get(Integer.parseInt(shortUrl));
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
