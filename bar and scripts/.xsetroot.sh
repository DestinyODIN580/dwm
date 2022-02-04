#! /bin/bash

# data e ora formattata
DAT="$(.local/bin/dt)"

# tempo di accensione
UPT="$(.local/bin/up)"

# traffico di rete
NET="$(nettraf)"

# volume e sorgente
VOL="$(.local/bin/vl)"

# memoria in uso
MEM="$(.local/bin/mm)"

# barra
xsetroot -name "| ${NET} | ${MEM} | ${VOL} | ${DAT} | Up ${UPT}"
