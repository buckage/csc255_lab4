/*
 * driver.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: russellbuck
 */

#include "heap.cpp"
#include <iostream>
#include <fstream>

using namespace std;

class Driver{

	ofstream fout;
	vector<int> inputData;


	void printHeap(string& description,Heap& heap){
		fout << description << endl;
		for (int i = 1; i <= heap.size(); i++){
				fout << heap.getElement(i) << " ";
		}
		fout << "\n\n";
	}



	void insertOne(
			Heap& heap,
			int element
	){
		fout << "Insert " << element << "\n";
		heap.insert(element);
		string print = "Heap after insert " + to_string(element);
//		printHeap(print, heap);
	}



	void deleteOne(
			Heap& heap
	){
		fout << "Delete " << heap.getElement(1) << "\n";
		heap.deleteMin();
	}



	void testData(){
		Heap heap;
		int root = 0;
		heap.insert(root);
		for (auto& it : inputData){
			string heapString = "Heap after inserting " + to_string(it);
			heap.insert(it);
			printHeap(heapString, heap);
		}
//		heap.switchLastTwo();
		string heapString1 = "Heap ";
		printHeap(heapString1, heap);

		insertOne(heap, 31);
		string heapString2 = "Heap after insert 31 ";
		printHeap(heapString2, heap);

		insertOne(heap, 14);
		string heapString3 = "Heap after insert 14 ";
		printHeap(heapString3, heap);

		string heapString4 = "Heap after deleteMin ";

//		while (heap.size() > 0){
//			heap.deleteMin();
//			printHeap(heapString4, heap);
//		}
	}



	void readData(string& inputFile){
		ifstream fin(inputFile);
		int data;
		while(fin >> data){
			inputData.push_back(data);
		}
	}



	public: void testFile(
			string inputFile,
			string outputFile
	){
		fout.open(outputFile);
		readData(inputFile);
		testData();
		fout.close();
	}
};



int main(){
	Driver d;
	for (int i = 1; i < 5; i++){
		string suffix = to_string(i) + ".txt";
		d.testFile("in" + suffix, "out" + suffix);
	}
}

