package algorithm.priority_queue;

import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class MyIndexPriorityQueue<K, T> {

    /** this only work with non primitive wrap class **/
    //T is payload and K is key

    public interface Comparator<T> {
        int compare(T l, T r);
    }

    Comparator<T> comparator;

    /** for heap array implementation **/
    private ArrayList<T> list = new ArrayList<>();

    /** for indexing mapping **/
    private HashMap<K, Integer> keyToIndex = new HashMap<>();
    private HashMap<Integer, K> indexToKey = new HashMap<>();

    /** create a root on 0 priority queue **/
    public MyIndexPriorityQueue(MyIndexPriorityQueue.Comparator<T> c) {
        this. comparator = c;
    }

    private void indexingSwap(int l, int r) {
        keyToIndex.put(indexToKey.get(r), l);
        keyToIndex.put(indexToKey.get(l), r);

        K temp = indexToKey.get(l);
        indexToKey.put(l, indexToKey.get(r));
        indexToKey.put(r, temp);

        Collections.swap(list, l, r);
    }

    private void indexingAdd(K key, T element) {
        list.add(element);
        keyToIndex.put(key, list.size() - 1);
        indexToKey.put(list.size() - 1, key);
    }

    private void indexingDel(int index) {
        K removedKey = indexToKey.get(index);
        keyToIndex.remove(removedKey);
        indexToKey.remove(index);
        list.remove(index);
    }

    /** move newly modified node at index to up **/
    private void swim(int index) {
        while (index > 0 && index < list.size()) {
            int pIndex = (index - 1) / 2;
            if (comparator.compare(list.get(index), list.get(pIndex)) < 0) {
                // for index pq
                indexingSwap(index, pIndex);
                index = pIndex;
            }
            else break;
        }
    }

    private void sink(int index) {
        while (2 * index + 1 < list.size() && index >= 0) {
            int cIndex = 2 * index + 1;
            if (2 * index + 2 < list.size() && comparator.compare(list.get(2 * index + 2), list.get(2 * index + 1)) < 0) {
                cIndex = 2 * index + 2;
            }
            if (comparator.compare(list.get(cIndex), list.get(index)) < 0) {
                // for index pq
                indexingSwap(index, cIndex);
                index = cIndex;
            }
            else break;
        }
    }

    /** insert new element into priority queue  **/
    public void insert(K key, T element) {
        indexingAdd(key, element);
        swim(list.size() - 1);
    }

    /** retrieve top element **/
    public Map.Entry<K, T> top() {
        if (list.isEmpty()) {
            return null;
        }
        else {
            return new AbstractMap.SimpleEntry<>(indexToKey.get(0), list.get(0));
        }
    }

    /** delete top element **/
    public void delTop() {
        if (list.isEmpty()) return;
        indexingSwap(0, list.size() - 1);
        indexingDel(list.size() - 1);
        sink(0);
    }

    /** delete arbitrary element **/
    /** The indexing is necessary since we need to know the index to delete **/
    /** However, the input is element, we have to use a reverse mapping**/
    public void delete(K key) {
        if (list.isEmpty() || !keyToIndex.containsKey(key)) return;
        int tempIndex = keyToIndex.get(key);
        indexingSwap(tempIndex, list.size() - 1);
        indexingDel(list.size() - 1);

        // actually can either swim or sink not both
        swim(tempIndex);
        sink(tempIndex);
    }

    /** update arbitrary element **/
    public void update(K key, T element) {
        if (!keyToIndex.containsKey(key)) return;
        int tempIndex = keyToIndex.get(key);
        list.set(tempIndex, element);
        swim(tempIndex);
        sink(tempIndex);
    }

    public int size() {
        return list.size();
    }

    public boolean containsKey(K key) {
        return keyToIndex.containsKey(key);
    }

    public T get(K key) {
        return list.get(keyToIndex.get(key));
    }

}
