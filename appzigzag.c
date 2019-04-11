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
    static bool switch_up_down = false;
    static bool up_down = false;
    static bool diag_up_down = false;
    
    std::cout << arr[m][k] << " ";
    
        while(1)
        {
            if(!switch_up_down)
            {
                if( k >= N && m >= N)
                {
                    break;
                }

                if(!up_down)
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
                else
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
                up_down = !up_down;
            }
            else
            {
                if( k >= N && m >= N)
                {
                    break;
                }
                
                if(diag_up_down)
                {
                    int row = m, col = k;
                    while(1)
                    {
                        if((m == col) && (k == row))
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
                    int row = m, col = k;
                    while(1)
                    {
                        if((m == col) && (k == row))
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
                diag_up_down = !diag_up_down;
            }
            switch_up_down = !switch_up_down;             
        }
    }

int main()
{

  int arr[][5] = {{1,2,3,4,5},
                  {6,7,8,9,10},
                  {11,12,13,14,15},
                  {16,17,18,19,20},
                  {21,22,23,24,25}};                
 
    // print the matrix in zig zag fashion
    // matrix 5*5 since the loop start from 0, passing 4  
    traverse(arr, 4);
}
