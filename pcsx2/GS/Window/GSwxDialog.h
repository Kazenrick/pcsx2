/*
 *	Copyright (C) 2020 Pcsx2 Team
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GNU Make; see the file COPYING.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#pragma once

#include "GS.h"
#include "GSSetting.h"

#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/notebook.h>
#include <wx/spinctrl.h>
#include <wx/wrapsizer.h>
#include <wx/statline.h>
#include <wx/filepicker.h>

namespace GSSettingsDialog
{

	class RendererTab : public wxPanel
	{
	public:
		wxCheckBox *acc_date_check, *eight_bit_check, *framebuffer_check, *flush_check, *edge_check, *mipmap_check;
		wxChoice *m_res_select, *m_anisotropic_select, *m_dither_select, *m_mipmap_select, *m_crc_select, *m_blend_select;
		wxSpinCtrl* thread_spin;

		RendererTab(wxWindow* parent);
	};

	class HacksTab : public wxPanel
	{
	public:
		wxCheckBox* hacks_check;
		wxCheckBox *align_sprite_check, *fb_convert_check, *auto_flush_check, *mem_wrap_check, *dis_depth_check;
		wxCheckBox *merge_sprite_check, *dis_safe_features_check, *preload_gs_check, *fast_inv_check, *wild_arms_check;

		wxChoice *m_half_select, *m_tri_select, *m_gs_offset_hack_select, *m_round_hack_select;
		wxSpinCtrl *skip_x_spin, *skip_y_spin, *tex_off_x_spin, *tex_off_y_spin;

		HacksTab(wxWindow* parent);
	};

	class DebugTab : public wxPanel
	{
	public:
		DebugTab(wxWindow* parent);
	};

	class RecTab : public wxPanel
	{
	public:
		wxCheckBox* record_check;
		wxSpinCtrl *res_x_spin, *res_y_spin, *thread_spin, *png_spin;
		wxDirPickerCtrl* dir_select;

		RecTab(wxWindow* parent);
	};

	class PostTab : public wxPanel
	{
	public:
		PostTab(wxWindow* parent);
	};

	class OSDTab : public wxPanel
	{
	public:
		OSDTab(wxWindow* parent);
	};

	class Dialog : public wxDialog
	{
		wxBoxSizer* m_top_box;
		wxChoice *m_renderer_select, *m_interlace_select, *m_texture_select, *m_adapter_select;
		RendererTab* m_renderer_panel;
		HacksTab* m_hacks_panel;
		DebugTab* m_debug_panel;
		RecTab* m_rec_panel;
		PostTab* m_post_panel;
		OSDTab* m_osd_panel;

	public:
		Dialog();
		~Dialog();
		void Reset();
		void Save();
	};

} // namespace GSSettingsDialog

extern bool RunwxDialog();
