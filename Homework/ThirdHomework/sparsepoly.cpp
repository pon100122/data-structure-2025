#include "sparsepoly.hpp"   

int main() {
   
    SparsePoly A;
    SparsePoly B;

    
    A.read();
    A.display("Poly A: ");

    
    B.read();
    B.display("Poly B: ");

    
    SparsePoly C;
    C.add(A, B);
    C.display("Poly C: ");

    return 0;
}
