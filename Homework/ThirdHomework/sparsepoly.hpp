#include <stdio.h>         
#include <vector>          

#define MAX_DEGREE 101      

class SparsePoly {
    int numTerms;                       
    std::vector<int> exponents;        
    std::vector<float> coefficients;   

public:
    
    SparsePoly() {}

    
    void read() {
        printf("항의 개수를 입력하세요: ");
        scanf("%d", &numTerms);  

        for (int i = 0; i < numTerms; i++) {
            float coef;
            int exp;
            printf("%d번째 항의 계수와 차수를 입력하세요 (예:계수 차수): ", i + 1);
            scanf("%f %d", &coef, &exp);
            if (coef != 0) {                  
                coefficients.push_back(coef);
                exponents.push_back(exp);
            }
        }
        numTerms = coefficients.size();       
    }

   
    void display(const char* str) {
        printf("%s", str);
        for (int i = 0; i < numTerms; i++) {
            printf("%.1fx^%d", coefficients[i], exponents[i]);
            if (i != numTerms - 1)
                printf(" + ");
        }
        printf("\n");
    }

    
    void add(SparsePoly a, SparsePoly b) {
        
        exponents.clear();
        coefficients.clear();

        int i = 0, j = 0;
        while (i < a.numTerms && j < b.numTerms) {
            if (a.exponents[i] == b.exponents[j]) {
                float sum = a.coefficients[i] + b.coefficients[j];
                if (sum != 0) {
                    coefficients.push_back(sum);
                    exponents.push_back(a.exponents[i]);
                }
                i++;
                j++;
            }
            else if (a.exponents[i] < b.exponents[j]) {
                coefficients.push_back(a.coefficients[i]);
                exponents.push_back(a.exponents[i]);
                i++;
            }
            else {
                coefficients.push_back(b.coefficients[j]);
                exponents.push_back(b.exponents[j]);
                j++;
            }
        }

        
        while (i < a.numTerms) {
            coefficients.push_back(a.coefficients[i]);
            exponents.push_back(a.exponents[i]);
            i++;
        }

        while (j < b.numTerms) {
            coefficients.push_back(b.coefficients[j]);
            exponents.push_back(b.exponents[j]);
            j++;
        }

        numTerms = coefficients.size(); 
    }
};
