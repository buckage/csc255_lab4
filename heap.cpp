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

			vector<int>::iterator it = find(heapVector.begin(), heapVector.end(), item);
			int child = it - heapVector.begin();
			int parent = (child)/2;

			cout << "child node " << item << " is being inserted at position " << child << endl;
			cout << "parent position is " << parent << "\n\n";
			while (parent > 0){
				if (heapVector[child] < heapVector[parent]){
					int temp = heapVector[child];
					heapVector[child] = heapVector[parent];
					heapVector[parent] = temp;
					percolateUp(heapVector[parent]);

				}
				break;
			}
		}



		void percolateDown(){


		}



 	 public:

		Heap(){

				vector<int> heapVector;

		}



		void insert(int& element){
			heapVector.push_back(element);
			cout << "push_back " << element << endl;
			percolateUp(element);
		}


		void deleteMin(){

		}



		int size(){
			return(heapVector.size()-1);
		}



		int& getElement(int index){
			return heapVector[index];
		}
};
