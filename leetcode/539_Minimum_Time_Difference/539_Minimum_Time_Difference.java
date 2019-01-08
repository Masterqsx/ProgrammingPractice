class Solution {
    private int transform(String timePoint) {
        String[] times = timePoint.split(":");
        return Integer.parseInt(times[0]) * 60 + Integer.parseInt(times[1]);
    }
    public int findMinDifference(List<String> timePoints) {
        List<Integer> minutesList = new ArrayList<>();
        for (String str : timePoints) minutesList.add(transform(str));
        Collections.sort(minutesList, (Integer l, Integer r) -> l - r);
        int minimum = 24 * 60;
        for (int i = 0; i < minutesList.size(); i++) {
            if (i > 0) minimum = Integer.min(minutesList.get(i) - minutesList.get(i - 1), minimum);
            if (i < minutesList.size() - 1) minimum = Integer.min(minutesList.get(i + 1) - minutesList.get(i), minimum);
            int target = 24 * 60 - minutesList.get(i);
            if (i == 0) minimum = Integer.min(minimum, minutesList.get(1) + target);
            else minimum = Integer.min(minimum, minutesList.get(0) + target);
        }
        return minimum;
    }
    
}
