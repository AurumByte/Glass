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
				idx = self.parent.Text_area.search(target, idx, nocase = 1, stopindex=END)
				if not idx: break
				lastidx = '%s+%dc' % (idx, len(target))
				self.parent.Text_area.tag_add(tag, idx, lastidx)
				idx = lastidx

			self.parent.Text_area.tag_config(tag, foreground = Color)
