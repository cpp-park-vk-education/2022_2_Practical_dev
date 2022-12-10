#!/bin/bash
Xvfb :1 -screen 0 1024x768x16 &
export QT_DEBUG_PLUGINS=1
export QT_QPA_PLATFORM=xcb
export QT_QPA_PLATFORM_PLUGIN_PATH=/opt/Qt/${QT_VERSION}/gcc_64/plugins
export QT_PLUGIN_PATH=/opt/Qt/${QT_VERSION}/gcc_64/plugins
export DISPLAY=:1
