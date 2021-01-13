# APremiere
# All these modules will be used in APremiere
from tkinter import *
from tkinter import filedialog
from tkinter import messagebox
import sys
import os

# Menu bar class
class Menu_Bar:
    def __init__(self, parent):
        Font_data = ("ubuntu", 9)
        Menu_options = Menu(parent.root, font = Font_data)
        parent.root.config(menu = Menu_options)

        File_drop = Menu(Menu_options, font = Font_data, tearoff = 0)
        File_drop.add_command(label = "New File", command = parent.new_file, accelerator = "Ctrl+N")
        File_drop.add_command(label = "Open File", command = parent.open_file, accelerator = "Ctrl+O")
        File_drop.add_command(label = "Save", command = parent.save_file, accelerator = "Ctrl+S")
        File_drop.add_command(label = "Save As", command = parent.save_file_as, accelerator = "Ctrl+Shift+S")
        File_drop.add_separator()
        File_drop.add_command(label = "Exit", command = parent.root.destroy)

        Code_drop = Menu(Menu_options, font = Font_data, tearoff = 0)
        Code_drop.add_command(label = "Run", command = parent.run_project)
        Code_drop.add_command(label = "Open Terminal", command = parent.open_terminal)

        About_drop = Menu(Menu_options, font = Font_data, tearoff = 0)
        About_drop.add_command(label = "Release Note", command = self.show_release_note)
        About_drop.add_separator()
        About_drop.add_command(label = "About", command = self.show_about_option)

        Menu_options.add_cascade(label = "File", menu = File_drop)
        Menu_options.add_cascade(label = "Code", menu = Code_drop)
        Menu_options.add_cascade(label = "Help", menu = About_drop)

    def show_about_option(self):
        note_title = "About APremiere"
        note_message = "APremiere\nis a code editor which you can use to code in many different programming languages."
        messagebox.showinfo(note_title, note_message)

    def show_release_note(self):
        note_title = "Release Notes"
        note_message = "APremiere Code editor"
        messagebox.showinfo(note_title, note_message)

# Status bar class
class Status_Bar:
    def __init__(self, parent):
        Font_data = ("ubuntu", 9)

        self.status = StringVar()
        self.status.set("APremiere 7")

        bar_data = Label(parent.Codearea,
                         textvariable = self.status,
                         fg = "#9da5b4",
                         bg = "#21252b",
                         font = Font_data)

        bar_data.pack(side = BOTTOM, fill = BOTH)
    def update_status(self, *args):
        if isinstance(args[0], bool):
            self.status.set("Your File Has Been Saved!")

        else:
            self.status.set("APremiere Code editor")

# APremiere (main) class
class APremiere:
    def __init__(self, root):
        Logo = PhotoImage(file = 'Logo.png')
        Font_data = ("ubuntu", 11)

        root.title("Untitled - APremiere")
        root.geometry("1350x675")
        root.iconphoto(False, Logo)

        self.root = root
        self.filename = None
        self.Codearea = Text(root,
                             font = Font_data,
                             selectbackground = "#474747",
                             insertbackground = "white",
                             fg = "#d7dae0",
                             bg = "#282c34",
                             undo = True,
                             wrap = WORD)

        self.scroll = Scrollbar(root, command = self.Codearea.yview)

        self.Codearea.configure(yscrollcommand = self.scroll.set)
        self.Codearea.pack(side = LEFT, fill = BOTH, expand = True)
        self.scroll.pack(side = RIGHT, fill = Y)

        self.menu = Menu_Bar(self)
        self.statusbar = Status_Bar(self)
        self.binding_keys()

    def run_project(self):
        os.system(f'glass {filename}')

    def open_terminal(self):
        os.system('start cmd.exe')

    def update_title(self, name = None):
        if name:
            self.root.title(f"{name} - APremiere")

        else:
            self.root.title("Untitled - APremiere")

    def new_file(self, *args):
        self.Codearea.delete(1.0, END)
        self.filename = None
        self.update_title()

    def open_file(self, *args):
        self.filename = filedialog.askopenfilename(
            defaultextension = "*.*",
            filetypes = [("All Files", "*.*"),
                         ("Markdown", ".md"),
                         ("Text Files", ".txt"),
                         ("Glass", ".a"),
                         ("C", ".c"),
                         ("C#", ".cs"),
                         ("C++", ".cpp"),
                         ("Java", ".java"),
                         ("Python", ".py"),
                         ("Css", ".css"),
                         ("HTML", ".html"),
                         ("JavaScript", ".js")])

        if self.filename:
            self.Codearea.delete(1.0, END)
            with open(self.filename, "r") as Data:
                self.Codearea.insert(1.0, Data.read())

            self.update_title(self.filename)

    def save_file(self, *args):
        if self.filename:
            try:
                textarea_content = self.Codearea.get(1.0, END)
                with open(self.filename, "w") as Data:
                    Data.write(textarea_content)

                self.statusbar.update_status(True)

            except Exception:
                pass

        else:
            self.save_file_as()

    def save_file_as(self, *args):
        try:
            new_file = filedialog.asksaveasfilename(
            initialfile = "Untitled.txt",
            defaultextension = ".txt",
            filetypes = [("All Files", "*.*"),
                         ("Markdown", ".md"),
                         ("Text Files", ".txt"),
                         ("Glass", ".a"),
                         ("C", ".c"),
                         ("C#", ".cs"),
                         ("C++", ".cpp"),
                         ("Java", ".java"),
                         ("Python", ".py"),
                         ("Css", ".css"),
                         ("HTML", ".html"),
                         ("JavaScript", ".js")])

            textarea_content = self.Codearea.get(1.0, END)
            with open(new_file, "w") as Data:
                Data.write(textarea_content)

            self.statusbar.update_status(True)
            self.filename = new_file
            self.update_title(self.filename)

        except Exception:
            pass

    def do_ctrl_backspace(self, *args):
        self.Codearea.delete("insert -4 chars", "insert")

    def binding_keys(self):
        self.Codearea.bind('<Control-n>', self.new_file)
        self.Codearea.bind('<Control-o>', self.open_file)
        self.Codearea.bind('<Control-s>', self.save_file)
        self.Codearea.bind('<Control-S>', self.save_file_as)
        self.Codearea.bind('<Control-BackSpace>', self.do_ctrl_backspace)
        self.Codearea.bind('<Key>', self.statusbar.update_status)

# Creating a tkinter root
if __name__ == '__main__':
    os.system('title APremiere Code editor')
    root = Tk()
    root.configure(background = '#21252b')
    Editor = APremiere(root)
    root.mainloop()
