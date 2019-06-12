'''Topic :Stacks in python
   Author : Chirag N Vijay
   Stack- Collectio of objects that are inserted and removed according to LIFO
          eg) Working of back and undo buttons,history tab in browsers.
          Abstract datatype
          Functions -
                    S.push(e)->Add element e to stack S
                    S.pop()->Removes and returns the top element from stack.
                    S.top()->Returns a reference to the top element
                    S.is_empty()->Returns true if S is empty
                    len(s)->Returns total number of items in stack S.
        Design Methodology -
                    Adapter-> Realizing Stack through list.
        Time Complexities(Usual)
                   Push - o(n)
                   pop  - o(n)
                   top  -o(1)
                   len  -o(1)
                   But we could amortize push and pop to o(1) also
         '''
class Empty(Exception):
    pass
class ArrayStack:
    def __init__(self):
        '''creating an empty stack'''
        self._data=[]
    def __len__(self):
        return len(self._data)
    def is_empty(self):
        return len(self._data)==0
    def push(self,e):
        self._data.append(e)
    def top(self):
        if self.is_empty():
            raise Empty('Stack is empty')
        return self._data[-1]
    def pop(self):
        if self.is_empty():
            raise Empty('Stack is empty')
        return self._data.pop()
    def display(self):
        return self._data[::-1]
S=ArrayStack()


while True:
    print("1:Push element into Stack")
    print("2:Pop element ")
    print("3:Print top element")
    print("4:Print length")
    print("5:Display Stack")
    print("6:Exit")
    ch=input("enter your choice")
    if ch=='1':
        e=input("enter element to be pushed")
        S.push(e)
    if ch=='2':
        print("Poped element is" + str(S.pop()))
    if ch=='3':
        print("Top element is " + str(S.top()))
    if ch=='4':
        print("Length of list is " +str(len(S)))
    if ch=='5':
        print(S.display())
    if ch=='6':
        break;


'''Matching delimiters'''
def matched(expr):
    left='({['
    right=')}]'
    S= ArrayStack()
    for c in expr:
        if c in left:
            S.push(c)
        elif c in right:
            if S.is_empty():
                return False
            if right.index(c)!=left.index(S.pop()):
                return False
    return S.is_empty
    
