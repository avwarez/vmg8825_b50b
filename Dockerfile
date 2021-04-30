FROM ubuntu:12.04

ENV HOME=/app
ENV BUILD_USER=builder
ENV BUILD_UID=1000

WORKDIR $HOME

RUN apt-get update && \
    apt-get install -y build-essential libncurses5-dev libncursesw5-dev zlib1g-dev gawk git gettext libssl-dev xsltproc rsync wget unzip python subversion vim sudo && \
    useradd -u $BUILD_UID $BUILD_USER && \
    echo "$BUILD_USER ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers && \
    locale-gen "en_US.UTF-8" && \
    dpkg-reconfigure locales && \
    ln -sf /bin/bash /bin/sh && \
    echo "foreign-architecture i386" > /etc/dpkg/dpkg.cfg.d/multiarch && \
    apt-get update && \
    apt-get install -y libc6:i386 libncurses5:i386 libstdc++6:i386 && \
    chmod ugo+rwx $HOME

CMD sudo -H -u $BUILD_USER /bin/bash
