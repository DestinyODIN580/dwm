/* configurazione dwm -- Marco Fiorillo */

#include <X11/XF86keysym.h>

/* tasti multimedia */
static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "0", "+5%",     NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "0", "-5%",     NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "0", "toggle",  NULL };
//atic const char *pause[] = {"/usr/bin/pactl", set

/* ----------------------------------------------------------------------------- */

/*"JoyPixels:pixelsize=12:antialias=true:autohint=true" */
/* {"monospace:size=12", "fontawesome:size=12" }; */
/* "monospace:size=11"; */

/* -------------------------------- ASPETTO ------------------------------------ */

static const unsigned int borderpx  = 2;						/* grandezza in pixel del bordo attorno alla finestra */
static const unsigned int gappx     = 5;						/* grandezza in pixel del gap tra le finestre */
static const unsigned int snap      = 32;						/* snap pixel */
static const int showbar            = 1;						/* 1 mostra la barra - 0 non mostra la barra */
static const int topbar             = 1;						/* 1 barra sopra - 0 barra sotto */
static const char dmenufont[]       = "JetBrains Mono:size=12";	/* font della barra di ricerca */
static const char *fonts[]          =   						/* font, fallback font (del sistema) */
{
	"JetBrains Mono:size=12",
	"fontawesome:size=12"
};

/* colori */
static const char col_black1[]      = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_orange[]      = "#f59542";
static const char col_violet[]		= "#773C5A";

#include "/home/sakura/.cache/wal/colors-wal-dwm.h"

/* colori applicati alla barra */
//static const char *colors[][3]      =
//{
//	/*               fg         bg          border  */
//	[SchemeNorm] = { col_gray3, col_black1, col_gray2  },	/* ciò che non e' selezionao */
//	[SchemeSel]  = { col_gray4, col_violet, col_violet },	/*  ciò che e' selezionto */
//};

/* ------------------------------------------------------------------- */
 
// static const char *tags[] = { "", "", "", "", "", "", "", "⚛", "", "" };

/* tag */
//static const char *tags[] = {"🏠", ">_", "", "� �� ", ""         };

//static const char *tags[] = {"1", "2", "3",
/* ---------------------------- TAG ---------------------------------- */

static const char *tags[] = {"🏠", ">_", " ", "⚛", ""};

#include "shiftview.c"

/* eccezioni e regole speciali */
static const Rule rules[] =
{
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* percentuale di schermo che prende la master window */
static const float mfact     = 0.55; /* [0.05..0.95] */

/* numero di master windows */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

/* layout (la prima opzione e' quella di default) */
static const Layout layouts[] =
{
	/* symbol     arrange function */
	{ "[]=",      tile },    /* tiling */
	{ "><>",      NULL },    /* floating */
	{ "[M]",      monocle }, /* fullscreen scorribile sulle app */
};

/* --------------------------------------------------------------------------- */

/* ------------------------------ SPECIAL KEY -------------------------------- */

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* ----------------------------------------------------------------------------- */

// static const char *monitor[] = { "/usr/bin/htop", NULL };/* htop */
// static const char *termcmd[]  = { "st", NULL };			/* come terminale */
// static const char *termcmd[]  = { "urxvt", NULL };		/* urxvt come terminale */

//#include "/home/sakura/.cache/wal/colors-wal-dmenu.h"

/* ---------------------------- SCRIPT/SHORTCUT  ------------------------------- */
static char *endx[] = { "/bin/sh", "-c", "endx", "externalpipe", NULL };
static char dmenumon[2] = "0";
//static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_black1, "-nf", col_gray3, "-sb", col_violet, "-sf", col_gray4, NULL };

static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_black1, "-nf", col_gray3, "-sb", sel_bg, "-sf", col_gray4, NULL };

/* shortcut personalizzate */
static const char *termcmd[]     = {"alacritty", NULL}; 	/* alacritty come terminale */
static const char *browser[]     = {"chromium", NULL};  	/* chromium come browser */
static const char *editor[]      = {"atom", NULL};			  /* atom come editor */
static const char *fileManager[] = {"dolphin", NULL};			/* dolphin come file manager */
static const char *textEditor[]  = {"gedit", NULL};				/* gedit come text editor */

/* --------------------------------------------------------------------------- */

/* ------------------------------ KEYBINDINGS -------------------------------- */

/* tasti e shortcut */
static Key keys[] =
{
	/* modifier                     key        function        argument */
    
    /* tasti multimediali */
	{ 3,                       		XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
	{ 3,                       		XF86XK_AudioMute,        spawn, {.v = mutevol } },
	{ 3,                      		XF86XK_AudioRaiseVolume, spawn, {.v = upvol } },

	/* chiusura */
	{ MODKEY,	                	XK_q,      killclient,     {0} },	// quit dall'applicazione in focus
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },	// quit da dwm
	
	/* searchbar */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd} },	// menu di delle applicazioni

	/* terminale rapido */
	{ MODKEY,	                	XK_Return, spawn,          {.v = termcmd } },	// terminale impostato di default

	/* opzioni finestra */
	{ MODKEY,                       XK_t,	   togglebar,      {0} },		  // toglie la barra dei tag
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1} },  // focus sull'applicazione precedente
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1} },  // focus sull'applicazione successiva
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },// rimpicciolisce verso sinistra
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },// ingrandisce verso destra
	{ MODKEY|ShiftMask,             XK_p,      togglefullscr,  {0} },         // fullscreen

	/* dimensioni delle finestre */
	{ MODKEY,                       XK_plus,   setgaps,       {.i = -1} },	  // ingrandisce
	{ MODKEY,                       XK_minus,  setgaps,       {.i = +1} },	  // rimpicciolisce
	{ MODKEY|ShiftMask,             XK_a,      setgaps,       {.i = 0 } },	  // toglie i gap laterali

    /* inverte le finestre */
	{ MODKEY,                       XK_i,      incnmaster,    {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,    {.i = -1 } },

    /*  */
	{ MODKEY,                       XK_z,	   zoom,          {0} },
	{ MODKEY,                       XK_Tab,    view,          {0} },

	/* layout (tiling, floating, monocole) */
	{ MODKEY|ShiftMask,             XK_t,      setlayout,     {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,     {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,     {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,     {0} },
	{ MODKEY|ShiftMask,             XK_p,  	   togglefloating,{0} },

	/* focus su altri monitor */
	{ MODKEY,                       XK_comma,  focusmon,      {.i = -1 } },				// focus sul monitor 1
	{ MODKEY,                       XK_period, focusmon,      {.i = +1 } },				// focus sul monitor 2

	/* shift su altri monitor */
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,        {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,        {.i = +1 } },

	{ MODKEY,                       XK_0,      view,          {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,           {.ui = ~0 } },
	{ MODKEY,              			XK_m,      shiftview,  	  { .i = +1 } },
	{ MODKEY,              			XK_n,      shiftview,     { .i = -1 } },


	/*	cambio fonte audio alternativi */
	{ MODKEY,                       XK_Up,     spawn,         SHCMD("pa-set 0") },
  	{ MODKEY,                       XK_Down,   spawn,         SHCMD("pa-set 1") },

	/*
  	{ MODKEY,                       XK_Left,   spawn,         {.v = mutevol } },
	*/

	/* tasti dei tag */
	TAGKEYS(                        XK_1,                     0)
	TAGKEYS(                        XK_2,                     1)
	TAGKEYS(                        XK_3,                     2)
	TAGKEYS(                        XK_4,                     3)
	TAGKEYS(                        XK_5,                     4)

	/*
	TAGKEYS(                        XK_6,                     5)
	TAGKEYS(                        XK_7,                     6)
	TAGKEYS(                        XK_8,                     7)
	TAGKEYS(                        XK_9,                     8)
	*/

	/* shortcut per l'apertura rapida delle app */
	{ MODKEY,												XK_2,			spawn,					{.v = termcmd } },
	{ MODKEY,												XK_3,			spawn,					{.v = fileManager } },
	{ MODKEY,												XK_4,			spawn,					{.v = editor } },
	{ MODKEY,												XK_5,			spawn,					{.v = browser } },

};

/* --------------------------------------------------------------------------- */

/* ----------------------------- MOUSE BINDINGS ------------------------------ */

/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] =
{
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
