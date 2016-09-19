class Solution {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
      if( (max(abs(D-F),abs(H-B))<=((D-B)+(H-F)) ) && (max(abs(C-E),abs(G-A))<=((C-A)+(G-E))) ){
        return abs(D-B)*abs(C-A)+abs(H-F)*abs(G-E)- min( min(abs(D-F),abs(H-B)) , min((D-B),(H-F)) ) * min( min(abs(C-E),abs(G-A)) , min((C-A),(G-E)) );
      }
      else
        return abs(D-B)*abs(C-A)+abs(H-F)*abs(G-E);
    }

};
