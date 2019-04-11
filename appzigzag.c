/*****************************************************************************
 *************************************************************************//**
 *
 * \file         appzigzag.c
 *
 * \abbrv        appzigzag
 *
 * \description  Print matrix in zig-zag fashion. 
 *****************************************************************************/
#include <iostream>
#include <string>

void traverse(int arr[][5], int N)
 {
    
    int m = 0, k = 0;
    
    static bool currentState = false;
    static bool strait = false;
    static bool up = false;
    
    std::cout << arr[m][k] << " "; 
        while(1)
        {
            if(!currentState)
            {
                if( k >= N && m >= N)
                {
                    break;
                }

                if(!strait && k <= N)
                {
                    if( k != N)
                    {
                        k++;
                    }
                    else
                    {
                        m++;
                    }
                    std::cout << arr[m][k] << " "; 
                }
                else if(m <= N)
                {
                    if( m != N)
                    {
                        m++;
                    }
                    else
                    {
                        k++;
                    }
                    std::cout << arr[m][k] << " "; 
                }
                strait = !strait;
            }
            else
            {
                if( k >= N && m >= N)
                {
                    break;
                }
                
                if(up)
                {
                    int prvA = m, pevB = k;
                    while(1)
                    {
                        if((m == pevB) && (k == prvA))
                        {
                            break;
                        }
                        else
                        { 
                            m -= 1;
                            k += 1;
                            std::cout << arr[m][k] <<" ";  
                        }
                    }
                }
                else
                {
                    int prvM = m, pevK = k;
                    while(1)
                    {
                        if((m == pevK) && (k == prvM))
                        {
                            break;
                        }
                        else
                        {           
                            m += 1;
                            k -= 1;
                            std::cout << arr[m][k] <<" ";  
                        }
                    }
                }
                up = !up;
            }
            currentState = !currentState;             
        }
    }

int main()
{

  int arr[][5] = {{1,2,3,4,5},
                  {6,7,8,9,10},
                  {11,12,13,14,15},
                  {16,17,18,19,20},
                  {21,22,23,24,25}};                
 
    traverse(arr, 4);
}