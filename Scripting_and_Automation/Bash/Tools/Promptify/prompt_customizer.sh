#!/bin/bash

source color_palette.sh

set_prompt() {
  PS1="${COLOR_BLUE}\u@\h ${COLOR_GREEN}\w ${COLOR_YELLOW}$(git_branch)${COLOR_RESET} > "
}

git_branch() {
  if git rev-parse --is-inside-work-tree &>/dev/null; then
    echo "$(git rev-parse --abbrev-ref HEAD)"
  else
    echo ""
  fi
}

set_prompt
