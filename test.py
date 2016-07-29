from tkinter import *

top = Tk()
BORDER_SIZE = 3
CELL_SIZE = 5
"""
E1 = Entry(top, borderwidth=1)
E1.pack(side=RIGHT)

E2 = Entry(top, borderwidth=7)
E2.pack(side=LEFT)
top.mainloop()

"""

Entry(top, text="1", width=CELL_SIZE).grid(row=0, column=0)
Entry(top, text="2", width=CELL_SIZE).grid(row=0, column=1)
Entry(top, text="3", width=CELL_SIZE).grid(row=0, column=3)

Entry(top, text="4", width=CELL_SIZE).grid(row=1, column=0)
Entry(top, text="5", width=CELL_SIZE).grid(row=1, column=1)
Entry(top, text="6", width=CELL_SIZE).grid(row=1, column=3)

Entry(top, text="7", width=CELL_SIZE).grid(row=3, column=0)
Entry(top, text="8", width=CELL_SIZE).grid(row=3, column=1)
Entry(top, text="9", width=CELL_SIZE).grid(row=3, column=3)

Frame(width=BORDER_SIZE, bg="black").grid(row=0, column=2, rowspan=5, sticky="ns") #vert
Frame(height=BORDER_SIZE, bg="black").grid(row=2, column=0, columnspan=5, sticky="ew") #hori

top.mainloop()