# All these modules need to be imported in Menubar
from tkinter import *
from tkinter import filedialog
from tkinter import messagebox

# This class will be used to make the menu for Quantum
class Menubar:
	def __init__(self, parent):
		Font_data = ("ubuntu", 9) # This Font data will be used to add font to menubar

		# Create a new menu object
		Menu_options = Menu(parent.root, font = Font_data)
		parent.root.config(menu = Menu_options)

		# Make a File menu in Menubar
		File_drop = Menu(Menu_options, font = Font_data, tearoff = 0, background = "white", foreground = "black")
		File_drop.add_command(label = "New File", command = parent.new_file, accelerator = "Ctrl+N")
		File_drop.add_command(label = "Open File", command = parent.open_file, accelerator = "Ctrl+O")
		File_drop.add_command(label = "Save", command = parent.save_file, accelerator = "Ctrl+S")
		File_drop.add_command(label = "Save As", command = parent.save_file_as, accelerator = "Ctrl+Shift+S")
		File_drop.add_separator()
		File_drop.add_command(label = "Exit", command = parent.root.destroy)

		About_drop = Menu(Menu_options, font = Font_data, tearoff = 0)
		About_drop.add_command(label = "Release Note", command = self.show_release_note)
		About_drop.add_separator()
		About_drop.add_command(label = "About", command = self.show_about_option)

		Menu_options.add_cascade(label = "File", menu = File_drop)
		Menu_options.add_cascade(label = "Help", menu = About_drop)

	def show_about_option(self):
		note_title = "About Quantum"
		note_message = "Quantum is an IDE which can be used to code in Glass."
		messagebox.showinfo(note_title, note_message)

	def show_release_note(self):
		note_title = "Release Notes"
		note_message = "Quantum 2021 [Version 0.3-alpha]"
		messagebox.showinfo(note_title, note_message)
