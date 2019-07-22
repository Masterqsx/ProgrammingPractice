package algorithm.skiplist;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MySkipList {

    public static class Entry {
        public int val;
        public String key;
        public Entry[] next;
        public Entry[] prev;
        public Entry(String key, int val, int maxLevel) {
            this.key = key;
            this.val = val;
            next = new Entry[maxLevel];
            prev = new Entry[maxLevel];
        }
    }

    private double p = 0.25;

    private int maxLevel = 32;

    private int getRandomLevel() {
        int level = 0;
        while (Math.random() < p && level < maxLevel) level++;
        return level;
    }

    private Entry head;

    private Entry tail;

    private Map<String, Entry> mapping;

    public MySkipList() {
        head = new Entry("^", Integer.MIN_VALUE, maxLevel);
        tail = new Entry("$", Integer.MAX_VALUE, maxLevel);
        for (int i = maxLevel - 1; i >= 0; i--) {
            head.next[i] = tail;
            tail.prev[i] = head;
        }
        mapping = new HashMap<>();
    }

    public void insert(String key, int val) {
        Entry[] cur = new Entry[maxLevel];
        Entry[] pre = new Entry[maxLevel];
        pre[maxLevel - 1] = head;
        cur[maxLevel - 1] = head.next[maxLevel - 1];
        for (int i = maxLevel - 1; i >= 0; i--) {
            if (i != maxLevel - 1) pre[i] = pre[i + 1];
            cur[i] = pre[i].next[i];
            while (cur[i].val < val) {
                pre[i] = cur[i];
                cur[i] = cur[i].next[i];
            }
        }
        Entry nEntry = new Entry(key, val, maxLevel);
        int nEntryLevel = getRandomLevel();
        for (int i = nEntryLevel; i >= 0; i--) {
            pre[i].next[i] = nEntry;
            nEntry.prev[i] = pre[i];

            nEntry.next[i] = cur[i];
            cur[i].prev[i] = nEntry;
        }
        mapping.put(key, nEntry);
    }

    public void delete(String key) {
        Entry delEntry = mapping.get(key);
        if (delEntry != null) {
            for (int i = maxLevel - 1; i >= 0; i--) {
                if (delEntry.prev[i] == null || delEntry.next[i] == null) continue;
                delEntry.prev[i].next[i] = delEntry.next[i];
                delEntry.next[i].prev[i] = delEntry.prev[i];
            }
        }
    }

    public List<String> search(int sVal, int eVal) {
        Entry[] cur = new Entry[maxLevel];
        Entry[] pre = new Entry[maxLevel];
        pre[maxLevel - 1] = head;
        cur[maxLevel - 1] = head.next[maxLevel - 1];
        List<String> res = new ArrayList<>();

        for (int i = maxLevel - 1; i >= 0; i--) {
            if (i != maxLevel - 1) pre[i] = pre[i + 1];
            cur[i] = pre[i].next[i];
            while (cur[i].val <= eVal) {
                pre[i] = cur[i];
                cur[i] = cur[i].next[i];
            }
        }

        while (pre[0] != head && pre[0].val >= sVal && pre[0].val <= eVal) {
            res.add(pre[0].key);
            pre[0] = pre[0].prev[0];
        }

        return res;
    }

}
