//Skyline de S1 = [x0, t1, x1, ..., xm-1, tm, xm]
//Skyline de S2 = [y0, w1, y1, ..., yk-1, wk, yk]

//m-1 + k-1 = n

//Invariante: xm >= y0


int* CalculaSkyline(int* S1, int* S2) {
    tamS1 = S1.length() - 1;
    tamS2 = S2.length() - 1;
    n = tamS1 + tamS2;
    Sk[0...2*n];
    k = 0;
    
    while (1) {
        //Se houver elementos em S1 e S2
        if i <= tamS1 && j <= tamS2 {
            xi = S1[i];
            yj = S2[j];
            
        }

        //Se não houver mais elementos em S2
        else if i <= tamS1 && j > tamS2 {
            xi = S1[i];
            yj = xi;
            
        }

        //Se não houver mais elementos em S1
        else if i > tamS1 && j <= tamS2 {
            yj = S2[j];
            xi = yj;
        }

        //Se não houver mais elementos em S1 e S2
        //i > tamS1 && j > tamS2 
        else {
            break;
        }



        if xi < yj {
            Sk[k] = xi;
            k = k + 1;
            //Não preciso preocupar-me com SegFault, pois o invariante me garante que não sairei fora do vetor
            Sk[k] = S1[i+1];
            k = k + 1;
            i = i + 2;
        }
        else if xi > yj {
            Sk[k] = yj;
            k = k + 1;
            //Não preciso preocupar-me com SegFault, pois o invariante me garante que não sairei fora do vetor
            Sk[k] = S2[j+1];
            k = k + 1;
            j = j + 2;
        }
        
        // Se xi == yj
        else {
        
            if j+1 <= tamS2 && i+1 <= tamS1 {
                if S1[i+1] > S2[j+1] {
                    Sk[k] = xi;
                    k = k + 1;
                    Sk[k] = S1[i+1];
                    k = k + 1;
                }
                else { 
                    Sk[k] = yj;
                    k = k + 1;
                    Sk[k] = S2[j+1];
                    k = k + 1;
                }
            }
            else if j+1 <= tamS2 {
                Sk[k] = yj;
                k = k + 1;
                Sk[k] = S2[j+1];
                k = k + 1;
            }
            else if i+1 <= tamS1 {
                Sk[k] = xi;
                k = k + 1;
                Sk[k] = S1[i+1];
                k = k + 1;
            } 
            else {
                //Se for o último elemento de ambos os vetores
                Sk[k] = xi;
                k = k + 1;
            }
            i = i + 2;
            j = j + 2;
        }
    }
    return Sk[0...k]
}