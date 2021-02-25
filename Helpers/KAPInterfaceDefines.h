/*
  ==============================================================================

    KAPInterfaceDefines.h
    Created: 25 Feb 2021 12:51:42am
    Author:  Johnathan Handy

  ==============================================================================
*/

#pragma once

const static int MAIN_PANEL_WIDTH = 700;
const static int MAIN_PANEL_HEIGHT = 300;

constexpr static int TOP_PANEL_WIDTH = MAIN_PANEL_WIDTH;
const static int TOP_PANEL_HEIGHT = 45;

const static int GAIN_PANEL_WIDTH = 100;
constexpr static int GAIN_PANEL_HEIGHT = MAIN_PANEL_HEIGHT - TOP_PANEL_HEIGHT;

constexpr static int CENTER_PANEL_WIDTH = MAIN_PANEL_WIDTH - (GAIN_PANEL_WIDTH * 2);
constexpr static int CENTER_PANEL_HEIGHT = GAIN_PANEL_HEIGHT;

constexpr static int CENTER_PANEL_MENU_BAR_WIDTH = CENTER_PANEL_WIDTH;
const static int CENTER_PANEL_MENU_BAR_HEIGHT = 35;

constexpr static int FX_PANEL_WIDTH = CENTER_PANEL_WIDTH;
constexpr static int FX_PANEL_HEIGHT = CENTER_PANEL_HEIGHT - CENTER_PANEL_MENU_BAR_HEIGHT;