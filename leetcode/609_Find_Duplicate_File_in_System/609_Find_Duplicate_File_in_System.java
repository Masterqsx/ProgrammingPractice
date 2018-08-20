class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> group = new HashMap<>();
        for (String path : paths) {
            String[] splitRes = path.split(" ");
            for (int i = 1; i < splitRes.length; i++) {
                String[] fileSplit = splitRes[i].split("\\(");
                if (!group.containsKey(fileSplit[1])) 
                    group.put(fileSplit[1], new ArrayList<String>());
                group.get(fileSplit[1]).add(splitRes[0] + "/" + fileSplit[0]);
            }
        }
        List<List<String>> res = new ArrayList<>();
        for (Map.Entry<String, List<String>> pair : group.entrySet()) {
            if (pair.getValue().size() > 1) res.add(pair.getValue());
        }
        return res;
    }
}
