class Solution {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
      return (D-B)*(C-A)+(H-F)*(G-E)-min(min(max(D-F,0),max(H-B,0)),min(D-B,H-F))* min(min(max(C-E,0),max(G-A,0)),min(C-A,G-E));
    }
};
