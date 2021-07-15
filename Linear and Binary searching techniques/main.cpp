#include <iostream>

#include "vector"
#include "Person.h"

int linearSearch(std::vector<int> &list, int SearchItem);

int binarySearch(std::vector<int> &s_list, int l, int r, int SearchValue);

int main() {
    std::vector<int> list {40,35,55,23,77,44,99};
    std::vector<int> s_list {10,20,30,40,50,65,80};//sorted


    //LINEAR SEARCH



    int input=0;
    std::cout<<"Enter the searching element in Linear search:";
    std::cin>>input;

    int result = linearSearch(list, input);

    if (result!=-1){
        std::cout<<"searching index:"<<result<<std::endl;
        std::cout<<"searching item:"<<list[result]<<std::endl<<std::endl;
    }else{
        std::cout << "element was not founded!!!" << std::endl<<std::endl;
    }




    //BINARY SEARCH

    int SearchValue;
    std::cout<<"Enter the searching element in Binary Search:";
    std::cin>>SearchValue;

    int search_element = binarySearch(s_list,0,  sizeof s_list, SearchValue );

    if(search_element != -1) {
        std::cout << "searching index: "<< search_element<<std::endl;
        std::cout << "searching item: "<<s_list[search_element] <<std::endl<<std::endl;
    }else{
        std::cout << "element not founded!!!" << std::endl<<std::endl;
    }



    //BINARY SEARCH WITH CLASSES


    auto *p = new Person(231,213,"", 88);
    int search_person = p->binarySearchWithId(2034);
    if(search_person != -1) {
        std::cout << "searching index of person: "<< search_person<<std::endl;

    }else{
        std::cout << "element not founded!!!" << std::endl;
    }

    return 0;

    }







int binarySearch(std::vector<int> &s_list, int l, int r, int SearchValue) {
    while(l<=r){
        int m= l + (r - 1) / 2;
        if(s_list[m]==SearchValue){
            return m;
        }
        if(s_list[m]<SearchValue){
            l=m+1;
        } else{
            r=m-1;
        }
    }
    return -1;

}


int linearSearch(std::vector<int> &list, int SearchItem){
 int counter=0;
 for (int item: list){
     if (item==SearchItem){
         return counter;

}
counter++;
 }
 return -1;
}
