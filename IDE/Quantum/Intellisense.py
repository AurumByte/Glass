# All these modules need to be imported in Intellisense
from tkinter import *

class Intellisense:
	def __init__(self, parent):
		self.parent = parent

	def intellisense(self, target, Color, tag, *args):
		self.parent.Text_area.tag_remove(tag, '1.0', END)
		if target:
			idx = '1.0'
			while 1:
				idx = self.parent.Text_area.search(target, idx, nocase = 1, stopindex = END)
				if not idx: break
				lastidx = '%s+%dc' % (idx, len(target))
				self.parent.Text_area.tag_add(tag, idx, lastidx)
				idx = lastidx

			self.parent.Text_area.tag_config(tag, foreground = Color)

	def Colorcode(self, *args):
		self.intellisense("using", "#ffb15e", "using_tag")
		self.intellisense("Shout", "#528ff7", "shout_tag")
		self.intellisense("Shoutln", "#528ff7", "shoutln_tag")
		self.intellisense("Get", "#528ff7", "get_tag")
		self.intellisense("GetKey", "#528ff7", "getkey_tag")
		self.intellisense("\"", "#a4ff7d", "doublequotes_tag")
		self.intellisense("'", "#a4ff7d", "singlequotes_tag")
