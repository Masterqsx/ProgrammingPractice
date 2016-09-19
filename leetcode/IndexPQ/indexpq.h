#ifndef _INDEXPQ_H_
#define _INDEXPQ_H_
#include <vector>
#include <unordered_map>

using namespace std;
template <typename T>
class IndexPQ {
  public:
    IndexPQ();
    void insert(T key, int nb);
    void modify(T key, int n_nb);
    void erase(T key);
    pair<T, int> minPQ();
    int operator[](T key);
    int count(T key);
    bool empty();
  private:
    unordered_map<T, int> index_map;
    vector<std::pair<T, int> > pq;
};

template <typename T>
IndexPQ<T>::IndexPQ(){}

template <typename T>
bool IndexPQ<T>::empty(){
  return pq.empty();
}

template <typename T>
void IndexPQ<T>::insert(T key, int nb){
  int cur_index = (int)pq.size();
  index_map[key] = cur_index;
  pq.push_back(pair<T, int>(key, nb));
  while (cur_index != 0 && pq[(cur_index-1)/2].second > nb){
    int parent = (cur_index-1)/2;
    index_map[pq[parent].first] = cur_index;
    index_map[pq[cur_index].first] = parent;
    swap(pq[parent], pq[cur_index]);
    cur_index = parent;
  }
}

template <typename T>
pair<T, int> IndexPQ<T>::minPQ(){
  return pq[0];
}

template <typename T>
int IndexPQ<T>::operator[](T key){
  return pq[index_map[key]].second;
}

template <typename T>
int IndexPQ<T>::count(T key){
  return (int)index_map.count(key);
}

template <typename T>
void IndexPQ<T>::modify(T key, int n_nb){
  int cur_index = index_map[key];
  if (n_nb > pq[cur_index].second){
    pq[cur_index].second = n_nb;
    int child = pq[cur_index*2+1].second>pq[cur_index*2+2].second ? cur_index*2+2 : cur_index*2+1;
    while (child < pq.size() && pq[child].second < n_nb){
      index_map[pq[child].first] = cur_index;
      index_map[pq[cur_index].first] = child;
      swap(pq[child], pq[cur_index]);
      cur_index = child;
      child = pq[cur_index*2+1].second>pq[cur_index*2+2].second ? cur_index*2+2 : cur_index*2+1;
    }
  }
  else if (n_nb < pq[cur_index].second){
    pq[cur_index].second = n_nb;
    int parent = (cur_index-1)/2;
    while (cur_index != 0 && pq[parent].second > n_nb){
      index_map[pq[parent].first] = cur_index;
      index_map[pq[cur_index].first] = parent;
      swap(pq[parent], pq[cur_index]);
      cur_index = parent;
      parent = (parent-1)/2;
    }
  }
}

template <typename T>
void IndexPQ<T>::erase(T key){
  int cur_index = index_map[key], o_nb = pq[cur_index].second;
  index_map.erase(key);
  swap(pq[cur_index], pq[pq.size()-1]);
  index_map[pq[cur_index].first] = cur_index;
  pq.pop_back();
  if (o_nb > pq[cur_index].second){
    int parent = (cur_index-1)/2;
    while (cur_index != 0 && pq[parent].second > pq[cur_index].second){
      index_map[pq[parent].first] = cur_index;
      index_map[pq[cur_index].first] = parent;
      swap(pq[parent], pq[cur_index]);
      cur_index = parent;
      parent = (parent-1)/2;
    }
  }
  else if (o_nb < pq[cur_index].second){
    int child = pq[cur_index*2+1].second>pq[cur_index*2+2].second ? cur_index*2+2 : cur_index*2+1;
    while (child < pq.size() && pq[child].second < pq[cur_index].second){
      index_map[pq[child].first] = cur_index;
      index_map[pq[cur_index].first] = child;
      swap(pq[child], pq[cur_index]);
      cur_index = child;
      child = pq[cur_index*2+1].second>pq[cur_index*2+2].second ? cur_index*2+2 : cur_index*2+1;
    }
  }
}
#endif
