# All these modules need to be imported in Menubar
from tkinter import *

# This class will be used to make the menu for Quantum
class Menubar:
	def __init__(self, parent):
		Font_data = ("ubuntu", 9) # This Font data will be used to add font to menubar

		# Create a new menu object
		Menu_options = Menu(parent.root, font = Font_data)
		parent.root.config(menu = Menu_options)

		# Make a File menu in Menubar
		File_drop = Menu(Menu_options, font = Font_data, tearoff = 0, background = "white", foreground = "black")
		File_drop.add_command(label = "New File", command = parent.new_file)
		File_drop.add_command(label = "Open File", command = parent.open_file)
		File_drop.add_command(label = "Save", command = parent.save_file)
		File_drop.add_command(label = "Save As", command = parent.save_file_as)
		File_drop.add_separator()
		File_drop.add_command(label = "Exit", command = parent.root.destroy)

		Menu_options.add_cascade(label = "File", menu = File_drop)
