package algorithm.priority_queue;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class MyIndexPriorityQueue<T> {

    /** this only work with non primitive wrap class **/

    public interface Comparator<T> {
        int compare(T l, T r);
    }

    Comparator<T> comparator;

    /** for heap array implementation **/
    private ArrayList<T> list = new ArrayList<>();

    /** for indexing mapping **/
    private HashMap<T, Integer> indexing = new HashMap<>();

    /** create a root on 0 priority queue **/
    public MyIndexPriorityQueue(MyIndexPriorityQueue.Comparator<T> c) {
        this. comparator = c;
    }

    private void indexingSwap(int l, int r) {
        indexing.put(list.get(r), l);
        indexing.put(list.get(l), r);
        Collections.swap(list, l, r);
    }

    private void indexingAdd(T element) {
        list.add(element);
        indexing.put(element, list.size() - 1);
    }

    private void indexingDel(int index) {
        indexing.remove(list.get(index));
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
    public void insert(T element) {
        indexingAdd(element);
        swim(list.size() - 1);
    }

    /** retrieve top element **/
    public T top() {
        if (list.isEmpty()) {
            return null;
        }
        else {
            return list.get(0);
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
    public void delete(T element) {
        if (list.isEmpty() || !indexing.containsKey(element)) return;
        int tempIndex = indexing.get(element);
        indexingSwap(tempIndex, list.size() - 1);
        indexingDel(list.size() - 1);

        // actually can either swim or sink not both
        swim(tempIndex);
        sink(tempIndex);
    }

    /** update arbitrary element **/
    public void update(T element) {
        if (!indexing.containsKey(element)) return;
        int tempIndex = indexing.get(element);
        swim(tempIndex);
        sink(tempIndex);
    }

}
