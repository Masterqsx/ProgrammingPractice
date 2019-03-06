package algorithm.priority_queue;

import java.util.ArrayList;
import java.util.Collections;

public class MyPriorityQueue<T> {

    public interface Comparator<T> {
        int compare(T l, T r);
    }

    Comparator<T> comparator;

    private ArrayList<T> list = new ArrayList<>();

    /** create a root on 0 priority queue **/
    public MyPriorityQueue(Comparator<T> c) {
        this. comparator = c;
    }

    /** move newly modified node at index to up **/
    private void swim(int index) {
        while (index != 0) {
            int pIndex = (index - 1) / 2;
            if (comparator.compare(list.get(index), list.get(pIndex)) < 0) {
                Collections.swap(list, index, pIndex);
                index = pIndex;
            }
            else break;
        }
    }

    private void sink(int index) {
        while (2 * index + 1 < list.size()) {
            int cIndex = 2 * index + 1;
            if (2 * index + 2 < list.size() && comparator.compare(list.get(2 * index + 2), list.get(2 * index + 1)) < 0) {
                cIndex = 2 * index + 2;
            }
            if (comparator.compare(list.get(cIndex), list.get(index)) < 0) {
                Collections.swap(list, index, cIndex);
                index = cIndex;
            }
            else break;
        }
    }

    /** insert new element into priority queue  **/
    public void insert(T element) {
        list.add(element);
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
        Collections.swap(list, 0, list.size() - 1);
        list.remove(list.size() - 1);
        sink(0);
    }


}