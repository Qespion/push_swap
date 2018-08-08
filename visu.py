# # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    visu.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avo <avo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/05 14:57:28 by oespion           #+#    #+#              #
#    Updated: 2018/08/06 16:08:11 by avo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import tkinter
import time

class MyFirstGUI:
    def __init__(self, master, mov, ret):
        self.master = master
        self.mov = mov
        self.i = 0
        self.master.geometry("{0}x{1}+0+0".format(root.winfo_screenwidth(), root.winfo_screenheight()))
        self.ret = ret.split()
        self.ret1 = ['']
        self.oP = tkinter.StringVar()
        self.vA = tkinter.StringVar()
        self.vB = tkinter.StringVar()
        self.oP.set("")
        self.vA.set("list A = " + ret)
        self.vB.set("list B = ")
        master.title("Push Swap Visualisation")

        self.op = tkinter.Label(master, textvariable=self.oP)
        self.op.pack()

        self.lista = tkinter.Label(master, textvariable=self.vA, wraplengt=1100)
        self.lista.pack()

        self.delim = tkinter.Label(master, text="-----------------------------")
        self.delim.pack()

        self.listb = tkinter.Label(master, textvariable=self.vB, wraplengt=1100)
        self.listb.pack()
        
        self.prev_button = tkinter.Button(master, text="Prev", command=self.prev)
        self.prev_button.pack()

        self.next_button = tkinter.Button(master, text="Next", command=self.next)
        self.next_button.pack()

        self.tri_button = tkinter.Button(master, text="tri auto", command=self.tri)
        self.tri_button.pack()

        self.reset_button = tkinter.Button(master, text="reset", command=self.reset)
        self.reset_button.pack()

        self.close_button = tkinter.Button(master, text="Quit", command=master.quit)
        self.close_button.pack()

    def update(self):
        self.vA.set("list A = " + ' '.join(self.ret))
        self.vB.set("list B = " + ' '.join(self.ret1))
        self.oP.set(self.mov[self.i])

    def handle(self, action):
        if (action == "pb"):
            if (self.ret1 == ['']):
                self.ret1.insert(0, self.ret[0])                
                self.ret1.pop()
            else:
                self.ret1.insert(0, self.ret[0])
            self.ret = self.ret[1:]
        elif (action == "ra"):
            self.ret.append(self.ret[0])
            self.ret = self.ret[1:]
        elif (action == "rb"):
            self.ret1.append(self.ret1[0])
            self.ret1 = self.ret1[1:]
        elif (action == "pa"):
            self.ret.insert(0, self.ret1[0])
            self.ret1 = self.ret1[1:]
        elif (action == "sa"):
            self.ret[0], self.ret[1] = self.ret[1], self.ret[0]
        elif (action == "sb"):
            self.ret1[0], self.ret1[1] = self.ret1[1], self.ret1[0]
        elif (action == "ss"):
            self.ret[0], self.ret[1] = self.ret[1], self.ret[0]
            self.ret1[0], self.ret1[1] = self.ret1[1], self.ret1[0]
        elif (action == "rr"):
            self.ret.append(self.ret[0])
            self.ret = self.ret[1:]
            self.ret1.append(self.ret1[0])
            self.ret1 = self.ret1[1:]
        elif (action == "rra"):
            self.ret.insert(0, self.ret[len(self.ret) - 1])
            self.ret.pop()
        elif (action == "rrb"):
            self.ret1.insert(0, self.ret1[len(self.ret1) - 1])
            self.ret1.pop()
        elif (action == "rrr"):
            self.ret1.insert(0, self.ret1[len(self.ret1) - 1])
            self.ret1.pop()
            self.ret.insert(0, self.ret[len(self.ret) - 1])
            self.ret.pop()
        self.update()

    def prev(self):
        print(self.mov[self.i])
        self.handle(mov[self.i])  
        if self.i == 0: 
            self.i = self.i
        else:
            self.i -= 1

    def next(self):
        self.handle(self.mov[self.i])
        print(self.mov[self.i])
        if self.i == len(mov) - 1:
            self.next_button.config(state = "disabled")
        else:
            self.i += 1

    def tri(self):
        self.handle(mov[self.i])
        self.i += 1
        if self.i < len(mov):
            self.master.after(int(50), self.tri)
        if self.i == len(mov):
            self.ret1 == ['']
    
    def reset(self):
        self.ret = ret.split()
        self.ret1 = ['']
        self.i = 0
        self.update()

root = tkinter.Tk()
with open(sys.argv[1], 'r') as my_file:
    ret = my_file.readline()
    mov = my_file.read().split()
my_gui = MyFirstGUI(root, mov, ret)
root.mainloop()
