/* exif-note.h
 *
 * Copyright (C) 2002 Lutz M�ller <lutz@users.sourceforge.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details. 
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __EXIF_NOTE_H__
#define __EXIF_NOTE_H__

typedef struct _ExifNote        ExifNote;
typedef struct _ExifNotePrivate ExifNotePrivate;

typedef struct _ExifNoteMethods ExifNoteMethods;
struct _ExifNoteMethods {
	void    (* free)      (ExifNote *);
	void    (* load_data) (ExifNote *, unsigned char *,  unsigned int);
	void    (* save_data) (ExifNote *, unsigned char **, unsigned int *);
	char ** (*get_value)  (ExifNote *);
};

struct _ExifNote {
	ExifNoteMethods methods;
	ExifNotePrivate *priv;
};

void exif_note_construct (ExifNote *note);

void exif_note_ref   (ExifNote *note);
void exif_note_unref (ExifNote *note);
void exif_note_free  (ExifNote *note);

#endif /* __EXIF_NOTE_H__ */