FROM hydronautics/stingray:control

WORKDIR /sauvc
COPY . /sauvc
RUN /bin/bash -c "source /opt/ros/humble/setup.bash && source /additional_packages/install/setup.bash && source /stingray/install/setup.bash && colcon build --packages-select sauvc_launch sauvc_missions"

COPY docker/control/entrypoint.sh /entrypoint.sh
RUN chmod +x  /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]

RUN echo 'source /sauvc/install/setup.bash' >> /root/.bashrc

CMD ["bash"]
