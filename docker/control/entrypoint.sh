#!/bin/bash
set -e

# Проверяем, существует ли файл setup.bash
if [ -f /sauvc/install/setup.bash ]; then
  echo "[INFO] Код уже сбилжен"
  source /sauvc/install/setup.bash
else
  echo "[INFO] Файл install/setup.bash не найден. Запускаем сборку..."
  # Выполняем сборку, при ошибке удаляем build, install, log и выходим

  source "/opt/ros/humble/setup.bash"
  source "/additional_packages/install/setup.bash"
  source /stingray_core/install/setup.bash
  source /stingray/install/setup.bash

  if ! colcon build --packages-select sauvc_launch sauvc_missions sauvc_pinger_finder; then
    echo "[ERROR] Сборка завершилась с ошибкой. Удаляем build, install, log..."
    rm -rf build install log
    exit 1
  fi
  echo "[INFO] Сборка завершена успешно. Выполняем source install/setup.bash..."
  source /sauvc/install/setup.bash
fi

exec "$@"
