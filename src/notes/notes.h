/*
  Copyright (C) 2003-2014 Paul Brossier <piem@aubio.org>

  This file is part of aubio.

  aubio is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  aubio is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with aubio.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef _AUBIO_NOTES_H
#define _AUBIO_NOTES_H

#ifdef __cplusplus
extern "C" {
#endif

/** notes detection object */
typedef struct _aubio_notes_t aubio_notes_t;

/** create notes detection object

  \param method notes detection type as specified in specdesc.h
  \param buf_size buffer size for phase vocoder
  \param hop_size hop size for phase vocoder
  \param samplerate sampling rate of the input signal

  \return newly created ::aubio_notes_t

*/
aubio_notes_t * new_aubio_notes (const char_t * method,
    uint_t buf_size, uint_t hop_size, uint_t samplerate);

/** delete notes detection object

  \param o notes detection object to delete

*/
void del_aubio_notes(aubio_notes_t * o);

/** execute note detection on an input signal frame

  \param o note detection object as returned by new_aubio_notes()
  \param in input signal of size [hop_size]
  \param out output notes of size [3] ? FIXME

*/
void aubio_notes_do (aubio_notes_t *o, const fvec_t * input, fvec_t * output);

#ifdef __cplusplus
}
#endif

#endif /* _AUBIO_NOTES_H */
