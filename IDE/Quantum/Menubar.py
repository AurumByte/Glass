# All these modules need to be imported in Menubar
from tkinter import *
from tkinter.simpledialog import *
from tkinter import filedialog
from tkinter import messagebox
from tkinter.colorchooser import askcolor
from tkinter.font import Font, families
from tkinter.scrolledtext import *
import time
import sys

# These are custom classes that will be used to add features to Quantum
from Statusbar import Statusbar

# This class will be used to make the menu for Quantum
class Menubar:
	def __init__(self, parent):
		Font_data = ("calibri", 9) # This Font data will be used to add font to menubar

		# Create a new menu object
		Menu_options = Menu(parent.root, font = Font_data)
		parent.root.config(menu = Menu_options)
		self.parent = parent

		Change_Theme = Menu(Menu_options, font = Font_data, tearoff = 0, background = "white", foreground = "black")

		# Make a File menu in Menubar
		File_drop = Menu(Menu_options, font = Font_data, tearoff = 0, background = "white", foreground = "black")
		File_drop.add_command(label = "New File", command = parent.new_file, accelerator = "Ctrl+N")
		File_drop.add_command(label = "Open File", command = parent.open_file, accelerator = "Ctrl+O")
		File_drop.add_command(label = "Save", command = parent.save_file, accelerator = "Ctrl+S")
		File_drop.add_command(label = "Save As", command = parent.save_file_as, accelerator = "Ctrl+Shift+S")
		File_drop.add_separator()
		File_drop.add_command(label = "Exit", command = parent.root.destroy)

		Edit_drop = Menu(Menu_options, font = Font_data, tearoff = 0, background = "white", foreground = "black")
		Edit_drop.add_command(label = "Undo", command = self.undo, accelerator = "Ctrl+Z")
		Edit_drop.add_command(label = "Redo", command = self.redo, accelerator = "Ctrl+Y")
		Edit_drop.add_separator()
		Edit_drop.add_command(label = "Cut", command = self.cut, accelerator = "Ctrl+X")
		Edit_drop.add_command(label = "Copy", command = self.copy, accelerator = "Ctrl+C")
		Edit_drop.add_command(label = "Paste", command = self.paste, accelerator = "Ctrl+V")
		Edit_drop.add_separator()
		Edit_drop.add_command(label = "Find", command = self.find, accelerator = "Ctrl+F")
		Edit_drop.add_separator()
		Edit_drop.add_command(label = "Select All", command = self.selectAll, accelerator = "Ctrl+A")

		Format_drop = Menu(Menu_options, font = Font_data, tearoff = 0, background = "white", foreground = "black")
		Format_drop.add_cascade(label = "Change Theme", menu = Change_Theme)
		Change_Theme.add_command(label = "Light Theme")
		Change_Theme.add_command(label = "Dark Theme")

		Format_drop.add_separator()
		Format_drop.add_command(label = "Bold", command = self.bold, accelerator = "Ctrl+B")
		Format_drop.add_command(label = "Italic", command = self.italic, accelerator = "Ctrl+I")
		Format_drop.add_command(label = "Underline", command = self.underline, accelerator = "Ctrl+U")
		Format_drop.add_command(label = "Overstrike", command = self.overstrike, accelerator = "Ctrl+T")
		Format_drop.add_command(label = "Add Date", command = self.addDate)

		About_drop = Menu(Menu_options, font = Font_data, tearoff = 0, background = "white", foreground = "black")
		About_drop.add_command(label = "Release Note", command = self.show_release_note)
		About_drop.add_separator()
		About_drop.add_command(label = "About", command = self.show_about_option)

		Menu_options.add_cascade(label = "File", menu = File_drop)
		Menu_options.add_cascade(label = "Edit", menu = Edit_drop)
		Menu_options.add_cascade(label = "Format", menu = Format_drop)
		Menu_options.add_cascade(label = "Help", menu = About_drop)

	# Help menu functions
	def show_about_option(self):
		note_title = "About Quantum"
		note_message = "Quantum is an IDE which can be used to code in Glass programming language."
		messagebox.showinfo(note_title, note_message)

	def show_release_note(self):
		note_title = "Release Notes"
		note_message = "\t  Light-Lens\nQuantum 2021 [Version 0.5.1-alpha]"
		messagebox.showinfo(note_title, note_message)

	# Edit menu functions
	def copy(self, *args):
		sel = self.parent.Text_area.selection_get()
		self.clipboard = sel

	def cut(self, *args):
		sel = self.parent.Text_area.selection_get()
		self.clipboard = sel
		self.parent.Text_area.delete(SEL_FIRST, SEL_LAST)

	def paste(self, *args):
		self.parent.Text_area.insert(INSERT, self.clipboard)

	def selectAll(self, *args):
		self.parent.Text_area.tag_add(SEL, "1.0", END)
		self.parent.Text_area.mark_set(0.0, END)
		self.parent.Text_area.see(INSERT)

	def undo(self, *args):
		self.parent.Text_area.edit_undo()

	def redo(self, *args):
		self.parent.Text_area.edit_redo()

	def find(self, *args):
		self.parent.Text_area.tag_remove('found', '1.0', END)
		target = askstring('Find', 'Find what:')
		if target:
			idx = '1.0'
			while 1:
				idx = self.parent.Text_area.search(target, idx, nocase = 1, stopindex=END)
				if not idx: break
				lastidx = '%s+%dc' % (idx, len(target))
				self.parent.Text_area.tag_add('found', idx, lastidx)
				idx = lastidx

			self.parent.Text_area.tag_config('found', foreground = '#f9f9f9', background = '#1054de')

	# Format menu functions
	def bold(self, *args):  # Works only if text is selected
		try:
			current_tags = self.parent.Text_area.tag_names("sel.first")
			if "bold" in current_tags: self.parent.Text_area.tag_remove("bold", "sel.first", "sel.last")
			else:
				self.parent.Text_area.tag_add("bold", "sel.first", "sel.last")
				bold_font = Font(self.parent.Text_area, self.parent.Text_area.cget("font"))
				bold_font.configure(weight = "bold")
				self.parent.Text_area.tag_configure("bold", font = bold_font)

		except: pass

	def italic(self, *args):  # Works only if text is selected
		try:
			current_tags = self.parent.Text_area.tag_names("sel.first")
			if "italic" in current_tags: self.parent.Text_area.tag_remove("italic", "sel.first", "sel.last")
			else:
				self.parent.Text_area.tag_add("italic", "sel.first", "sel.last")
				italic_font = Font(self.parent.Text_area, self.parent.Text_area.cget("font"))
				italic_font.configure(slant = "italic")
				self.parent.Text_area.tag_configure("italic", font = italic_font)

		except: pass

	def underline(self, *args):  # Works only if text is selected
		try:
			current_tags = self.parent.Text_area.tag_names("sel.first")
			if "underline" in current_tags: self.parent.Text_area.tag_remove("underline", "sel.first", "sel.last")
			else:
				self.parent.Text_area.tag_add("underline", "sel.first", "sel.last")
				underline_font = Font(self.parent.Text_area, self.parent.Text_area.cget("font"))
				underline_font.configure(underline = 1)
				self.parent.Text_area.tag_configure("underline", font = underline_font)

		except: pass

	def overstrike(self, *args):  # Works only if text is selected
		try:
			current_tags = self.parent.Text_area.tag_names("sel.first")
			if "overstrike" in current_tags: self.parent.Text_area.tag_remove("overstrike", "sel.first", "sel.last")
			else:
				self.parent.Text_area.tag_add("overstrike", "sel.first", "sel.last")
				overstrike_font = Font(self.parent.Text_area, self.parent.Text_area.cget("font"))
				overstrike_font.configure(overstrike = 1)
				self.parent.Text_area.tag_configure("overstrike", font = overstrike_font)

		except: pass

	def addDate(self):
		full_date = time.localtime()
		day = str(full_date.tm_mday)
		month = str(full_date.tm_mon)
		year = str(full_date.tm_year)
		date = day + '/' + month + '/' + year
		self.parent.Text_area.insert(INSERT, date, "a")
