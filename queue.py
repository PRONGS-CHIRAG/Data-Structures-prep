'''Topic : Queues in python
   Author: Chirag N Vijay
   Queues:-
         Abstract data structure similar to stacks.
         Follow FIFO Principle.
         Insertion happens at the rear end and Removal happens at the Front end.
         eg) Customer service,wait-list at restaraunts,networked printer.
         Only the item which has been there for the longest time can be removed.
  Operations :-
        Q.enqueue(e)- Insert e to the back of queue Q.
        Q.dequeue()- Remove and return the first element from the queue Q.
        Q.first()-Returns the first element from the Queue Q.
        Q.is_empty()-Returns True if queue Q is empty.
        len(Q)- Returns length of the queue Q.
  All the operations are achieved within o(1) time.
         '''
class Empty(Exception):
    pass
class ArrayQueue():
    CAPACITY=10
    def __init__(self):
        self._data = [None] * ArrayQueue.CAPACITY
        self._size = 0
        self._front = 0
    def __len__(self):
        return self._size
    def is_empty(self):
        return self._size==0
    def first(self):
        if self.is_empty():
            raise Empty('Queue is empty')
        return self._front
    def enqueue(self,e):
        if self._size==len(self._data):
            self._resize(2*len(self._data))
        avail=(self._front + self._size)%len(self._data)
        self._data[avail]=e
        self._size += 1
    def _resize(self,cap):
        old=self._data
        self._data=None * cap
        walk=self._front
        for k in range(self._size):
            self._data[k]=old[walk]
            walk =(1+walk)%len(old)
        self._front=0
    def dequeue(self):
        if self.is_empty():
            raise Empty('Queue is empty')
        answer=self._data[self._front]
        self._data[self._front]=None
        self._front=(self._front +1)%len(self._data)
        self._size -= 1
        return answer
    def display(self):
        return self._data
S=ArrayQueue()
while True:
    print("1:Insert into queue")
    print("2:Remove element ")
    print("3:Print front element")
    print("4:Print length")
    print("5:Display Queue")
    print("6:Exit")
    ch=input("enter your choice")
    if ch=='1':
        e=input("enter element to be pushed")
        S.enqueue(e)
    if ch=='2':
        print("Poped element is" + str(S.dequeue()))
    if ch=='3':
        print("Top element is " + str(S.first()))
    if ch=='4':
        print("Length of list is " +str(len(S)))
    if ch=='5':
        print(S.display())
    if ch=='6':
        break;
