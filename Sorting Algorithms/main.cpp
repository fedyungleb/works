#include <iostream>
#include <vector>
#include <cstring>
#define N 10

using namespace std;

int counter=0;
void swap(int*x, int*y){
    int temp= *x;
    *x=*y;   //x=y
    *y=temp;  //y=x
}

void bubbleSort( int array[], int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                counter++;
            }
        }
    }
}
        void displayAlgorithm(){
            cout<<"========================Bubble Sort======================================"<<endl;
        int array[]={44,24,76,32,99,123,15,56};
        cout<<"Unsorted list:";
            for (int &i: array) {
                cout<<i<<"  ";

            }
            cout<<endl;
            int size= sizeof(array) / sizeof(array[0]);
          bubbleSort(array, size);{
                cout<<"Sorted list:";
                for (int &i: array) {
                    cout<<i<<"  ";
          }

    }
            cout<<"\nIterations:"<<counter<<endl<<endl;
}


void mergeSort(vector<int> &a, size_t start, size_t end)
{
    if (end - start < 2)
        return;
    if (end - start == 2)
    {
        if (a[start] > a[start + 1])
            swap(a[start], a[start + 1]);
        return;
    }
    mergeSort(a, start, start + (end - start) / 2);
    mergeSort(a, start + (end - start) / 2, end);
    vector<int> b;
    size_t b1 = start;
    size_t e1 = start + (end - start) / 2;
    size_t b2 = e1;
    while (b.size() < end - start)
    {
        if (b1 >= e1 || (b2 < end && a[b2] <= a[b1]))
        {
            b.push_back(a[b2]);
            ++b2;
        }
        else
        {
            b.push_back(a[b1]);
            ++b1;
        }
    }
    for (size_t i = start; i < end; ++i)
        a[i] = b[i - start];

}

void displayMerge()
{
    cout<<"========================MERGE SORT======================================"<<endl;
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);
    for (size_t i = 0; i < v.size(); ++i)
        swap(v[i], v[rand() % (v.size() - i) + i]);
    for (auto i: v)
        cout << i << " ";
    cout << endl;
    mergeSort(v, 0, v.size());
    for (auto i: v)
        cout << i << " ";
    cout << endl;
}

int main() {

displayAlgorithm();
displayMerge();

    cout<<"========================Alphabet sorting ======================================"<<endl;
    int i,j;
    char words[N][30], cur[30];
    cout<<"Your words:\n";
    for(i=0;i<N;i++)
        cin.getline(words[i],30);

    for(i=0;i<N-1;i++)
        for(j=i+1;j<N;j++)
            if(strcmp(words[i],words[j])>0)
            {   strcpy(cur,words[i]);
                strcpy(words[i],words[j]);
                strcpy(words[j],cur);
            }
    cout<<"Results:\n";
    for(i=0;i<N;i++)
        cout<<words[i]<<"\n";



    return 0;
}
