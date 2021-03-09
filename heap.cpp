/*
 * heap.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: russellbuck
 */

#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;


class Heap{

 	 private:

		vector<int> heapVector;


		void percolateUp(int& item){
//			cout << item << " has been passed into percolateUp\n" << endl;

			vector<int>::iterator it = find(heapVector.begin(), heapVector.end(), item);
			int index = it - heapVector.begin();
//			cout << index << "\n";
			while (((index+1)/ 2) > 0){
				if (heapVector[index] < heapVector[((index)/2)]){
					int temp = heapVector[(index)/2];
					heapVector[(index)/2] = heapVector[index];
					heapVector[index] = temp;
				}
				index = (index)/2;
			}
		}



		int minimumChildNode(int i){
					return ((i*2+1) > heapVector.size()) ? i * 2 : (heapVector[i*2] < heapVector[i*2+1]) ? i*2 : i*2+1;
		}



		void percolateDown(){
			int i = 1;
			while ((i*2) <= heapVector.size()){
				int minChild = minimumChildNode(i);
				if (heapVector[i] > heapVector[minChild]){
					int temp = heapVector[i];
					heapVector[i] = heapVector[minChild];
					heapVector[minChild] = temp;
				}
				i = minChild;
			}
		}



 	 public:

		Heap(){
				vector<int> heapVector;
			}



		void insert(int& element){
				heapVector.push_back(element);
				vector<int>::iterator it = find(heapVector.begin(), heapVector.end(), element);
				int index = it - heapVector.begin();
				percolateUp(heapVector[index]);
			}



		void deleteMin(){
			heapVector[1] = 999999;
			percolateDown();
			heapVector.erase(remove(heapVector.begin(), heapVector.end(), 999999), heapVector.end());
		};



		int size(){
			return(heapVector.size()-1);
		}



		int& getElement(int index){
			return heapVector[index];
		}



		void switchLastTwo(){
			int size = heapVector.size() -1;
			int tmp = heapVector[size];
			heapVector[size] = heapVector[size-1];
			heapVector[size-1] = tmp;

		}





};
