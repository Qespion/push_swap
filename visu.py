# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    visu.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oespion <oespion@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/05 14:57:28 by oespion           #+#    #+#              #
#    Updated: 2018/08/05 17:42:22 by oespion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
from tkinter import Tk, Label, Button

class MyFirstGUI:
    def __init__(self, master):
        self.master = master
        master.title("Push Swap Visualisation")

        self.lista = Label(master, text="list a = " + ret)
        self.lista.pack()

        if (ret1):
            self.listb = Label(master, text="list b = " + ret1)
            self.listb.pack()
        else:
            self.listb = Label(master, text="list b is Empty")
            self.listb.pack()

        self.prev_button = Button(master, text="Prev", command=self.prev)
        self.prev_button.pack()

        self.next_button = Button(master, text="Next", command=self.next)
        self.next_button.pack()

        self.close_button = Button(master, text="Quit", command=master.quit)
        self.close_button.pack()

    def prev(self):
        print("go prev!")

    def next(self):
        print("go next!")

root = Tk()
with open(sys.argv[1], 'r') as my_file:
    ret = my_file.readline()
    mov = my_file.read()
ret1 = None
my_gui = MyFirstGUI(root)
root.mainloop()
