# Отчёт по лабораторной работе №1-2 по курсу “Языки и методы программирования

<b>Студент группы:</b> <ins>М80-108Б-22 Старостина Анна Андреевна, № по списку 20</ins>

<b>Контакты e-mail:</b> <ins>st4ro5tinaa@yandex.ru</ins>

<b>Работа выполнена:</b> «27» <ins>сентября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «1» <ins>октября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Операционная среда OC UNIX.

## 2. Цель работы
Изучение и освоение программного обеспечения OC UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде OC UNIX.

## 3. Задание
Приобретение основных навыков в работе OC UNIX на рабочих станциях в окнах текстовых терминалов. Навигация в иерархической файловой системе OC UNIX. Создание, копирование, переименование и удаление файлов и каталогов. Работа с текстовым редактором Emacs. Освоение сервисных функций, оконных интерфейсов Unix.

## 4. Оборудование

Ноутбук Macbook Pro

Процессор: apple m2

Монитор: 2560х1600

## 5. Программное обеспечение

Операционная система семейства: Linux Ubuntu 22.04.1

Интерпретатор команд: bash 5.0.17(1)

Система программирования:

Редактор текстов: emacs

Утилиты операционной системы: команды date, hostname, finger, cp, touch, find, who, pwd, ls, cd, mv, rm, cat, ps, mkdir, rmdir, ruptime, rwho, uptime, whoami

Прикладные системы и программы: gnuplot, dc

Местонахождение и имена файлов программ и данных:

## 6. Идея, метод, алгоритм решения задачи

В формах: словесной, псевдокода, графической [блок схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями.

Вывод информации о пользователе и системе с помощью команд: who, rwho, uptime, ruptime, whoami, man, date

Работа с каталогами с помощью команд ls, cd, mkdir, rmdir, pwd

Работа с текстовыми файлами с помощью команд: cat, mv, rm, cp

Работа с текстовым редактором Emacs с помощью команд: cat Emacs

Работа с утилитой gnuplot  с помощью команд plot, splot, set parametric, [x]range

## 7. Сценарий выполнения работы

[План работы, первоначальный текст программы в черновике ( можно на отдельном листе) и тесты либо соображения по тестированию]

Man - показывает инструкцию к программам и командам Linux

Whoami (или who am i) - показывает идентификатор пользователя

Who - показывает перечень пользователей (для определения того, какие пользователи работают в данный момент на локальной машине)

Rwho - показывает перечень пользователей в локальной сети (какие пользователи работают на всех доступных UNIX машинах)

Date - показывает текущую дату и время

Tty - показывает адрес терминала

uname -a - показывает информацию о операционной системе

Uname - печатает основную информацию об имени операционной системы и системном оборудовании

Ruptime -показывает строку состояния пользователей в сети( какие узлы сети в настоящий момент доступны, а какие нет)

Hostname - определяет название компьютера и использует преимущественно для идентификации компьютера в сети

Finger - сообщает информацию о пользователях, вошедших в систему в настоящее время в операционной системе

Ls - показывает содержимого каталога

Ls -a - показывает скрытые файлы

Ls -F - наглядно отображает тип файла

Ls - l - более читабельный список

Ps - список программ, выполняемых в данный момент

Pwd - показывает текущую директорию (для определения местанахождения в файловой системе; по этой команде отображается полный путь к текущей директории)

Cd - перемещение по каталогам

Cat - показывает содержимое файла

Cat > - помещение текста с клавиатуры в файл

Rm - удаление файла

Mkdir - создание новых каталогов

Rmdir - удаление каталога

Cp - копирование файлов и каталогов

Mv - переименование файлов и каталогов

Find - позволяет искать файлы в каталогах, подкаталогах

Uptime - вызывает время работы сервера

Chmod - права доступа к файлам

Plot - строит двумерный график функции

Splot - строит график функции в трехмерном пространстве

Set parametric - возможность использовать параметры

Set [x]range - устанавливает диапазон значений переменной х

## 8. Распечатка протокола

Подклеить листинг окончательного варианта программы с тестовыми примерами, подписанный преподавателем.
```
ann@ann:~$ ls

d1   gnuplot   snap    Документы   Изображения   Общедоступные   Шаблоны

d2   set       Видео   Загрузки    Музыка       'Рабочий стол'

ann@ann:~$ ls -a

.               .cache     .gnupg             .pki       .sudo\_as\_admin\_successful   Изображения

..              .config    gnuplot            .profile   .viminfo                    Музыка

.bash\_history   d1         .gnuplot\_history   set        Видео                       Общедоступные

.bash\_logout    d2         .lesshst           snap       Документы                  'Рабочий стол'

.bashrc         .emacs.d   .local             .ssh       Загрузки                    Шаблоны

ann@ann:~$ ls -F

d1/   gnuplot   snap/    Документы/   Изображения/   Общедоступные/   Шаблоны/

d2/   set       Видео/   Загрузки/    Музыка/       'Рабочий стол'/

ann@ann:~$ ls -l

total 44

drwxrwxr-x 3 ann ann 4096 сен 27 19:12  d1

drwxrwxr-x 2 ann ann 4096 сен 27 19:12  d2

- rw-rw-r-- 1 ann ann    0 сен 23 12:51  gnuplot
- rw-rw-r-- 1 ann ann    0 сен 23 15:04  set

drwx------ 4 ann ann 4096 окт  1 09:00  snap

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Видео

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Документы

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Загрузки

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Изображения

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Музыка

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Общедоступные

drwxr-xr-x 2 ann ann 4096 окт  8  2022 'Рабочий стол'

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Шаблоны

ann@ann:~$ ruptime

ann           up     ??:??,     1 user,   load 0.38, 0.39, 0.19

ann@ann:~$ whoami

ann

ann@ann:~$ tty

/dev/pts/0

ann@ann:~$ hostname

ann

ann@ann:~$ uname

Linux

ann@ann:~$ uname -a

Linux ann 5.15.0-48-generic #54-Ubuntu SMP Fri Aug 26 13:31:33 UTC 2022 aarch64 aarch64 aarch64 GNU/Linux

ann@ann:~$ rwho

ann      ann:tty2 Oct  8 01:27 :-53

ann@ann:~$ finger `whoami`

Login: ann            			Name: ann

Directory: /home/ann                	Shell: /bin/bash

On since Sat Oct  8 01:27 (UTC) on tty2 from tty2

No mail.

No Plan.

ann@ann:~$ pwd

/home/ann

ann@ann:~$ who

ann      tty2         2022-10-08 01:27 (tty2)

ann@ann:~$ man ls

ann@ann:~$ cd /

ann@ann:/$ cd /bin

ann@ann:/bin$ ls

'['                                   grub-kbdcomp                       scanimage

aa-enabled                           grub-menulst2cfg                   scp

aa-exec                              grub-mkfont                        scp-dbus-service

aa-features-abi                      grub-mkimage                       screen

aarch64-linux-gnu-addr2line          grub-mklayout                      screendump

aarch64-linux-gnu-ar                 grub-mknetdir                      script

aarch64-linux-gnu-as                 grub-mkpasswd-pbkdf2               scriptlive

aarch64-linux-gnu-c++filt            grub-mkrelpath                     scriptreplay

aarch64-linux-gnu-cpp                grub-mkrescue                      scsi\_logging\_level

aarch64-linux-gnu-cpp-11             grub-mkstandalone                  scsi\_mandat

aarch64-linux-gnu-dwp                grub-mount                         scsi\_readcap

aarch64-linux-gnu-elfedit            grub-render-label                  scsi\_ready

aarch64-linux-gnu-gold               grub-script-check                  scsi\_satl

aarch64-linux-gnu-gprof              grub-syslinux2cfg                  scsi\_start

aarch64-linux-gnu-ld                 gsettings                          scsi\_stop

aarch64-linux-gnu-ld.bfd             gsf                                scsi\_temperature

aarch64-linux-gnu-ld.gold            gsf-office-thumbnailer             sdiff

aarch64-linux-gnu-nm                 gsf-vba-dump                       sdptool

aarch64-linux-gnu-objcopy            gstreamer-codec-install            seahorse

aarch64-linux-gnu-objdump            gtbl                               sed

aarch64-linux-gnu-ranlib             gtf                                select-default-iwrap

aarch64-linux-gnu-readelf            gtk4-builder-tool                  select-editor

aarch64-linux-gnu-size               gtk4-encode-symbolic-svg           sensible-browser

aarch64-linux-gnu-strings            gtk4-launch                        sensible-editor

aarch64-linux-gnu-strip              gtk4-query-settings                sensible-pager

aconnect                             gtk4-update-icon-cache             seq

add-apt-repository                   gtk-builder-tool                   session-migration

addpart                              gtk-encode-symbolic-svg            sessreg

addr2line                            gtk-launch                         setarch

airscan-discover                     gtk-query-settings                 setfacl

alsabat                              gtk-update-icon-cache              setfont

alsaloop                             gunzip                             setkeycodes

alsamixer                            gzexe                              setleds

alsatplg                             gzip                               setlogcons

alsaucm                              h2ph                               setmetamode

amidi                                h2xs                               setpci

amixer                               hardlink                           setpriv

apg                                  hciattach                          setsid

apgbfm                               hciconfig                          setterm

aplay                                hcitool                            setupcon

aplaymidi                            hd                                 setxkbmap

apport-bug                           head                               sftp

apport-cli                           HEAD                               sg

apport-collect                       helpztags                          sg\_bg\_ctl

apport-unpack                        hex2hcd                            sg\_compare\_and\_write

appres                               hexdump                            sg\_copy\_results

appstreamcli                         host                               sg\_dd

apropos                              hostid                             sg\_decode\_sense

apt                                  hostname                           sg\_emc\_trespass

apt-add-repository                   hostnamectl                        sg\_format

apt-cache                            htop                               sg\_get\_config

apt-cdrom                            hwe-support-status                 sg\_get\_elem\_status

apt-config                           ibus                               sg\_get\_lba\_status

aptdcon                              ibus-daemon                        sg\_ident

apt-extracttemplates                 ibus-setup                         sginfo

apt-ftparchive                       iceauth                            sg\_inq

apt-get                              ico                                sg\_logs

apt-key                              iconv                              sg\_luns

apt-mark                             id                                 sg\_map

apt-sortpkgs                         iecset                             sg\_map26

ar                                   im-config                          sgm\_dd

arch                                 im-launch                          sg\_modes

arecord                              info                               sg\_opcodes

arecordmidi                          infobrowser                        sgp\_dd

as                                   infocmp                            sg\_persist

aseqdump                             infotocap                          sg\_prevent

aseqnet                              install                            sg\_raw

aspell                               install-info                       sg\_rbuf

aspell-import                        install-printerdriver              sg\_rdac

atobm                                instmodsh                          sg\_read

automat-visualize3                   ionice                             sg\_read\_attr

avahi-browse                         ip                                 sg\_read\_block\_limits

avahi-browse-domains                 ipcmk                              sg\_read\_buffer

avahi-publish                        ipcrm                              sg\_readcap

avahi-publish-address                ipcs                               sg\_read\_long

avahi-publish-service                ipod-read-sysinfo-extended         sg\_reassign

avahi-resolve                        ipod-time-sync                     sg\_referrals

avahi-resolve-address                iptables-xml                       sg\_rep\_pip

avahi-resolve-host-name              ischroot                           sg\_rep\_zones

avahi-set-host-name                  iscsiadm                           sg\_requests

avinfo                               isdv4-serial-debugger              sg\_reset

awk                                  isdv4-serial-inputattach           sg\_reset\_wp

axfer                                ispell-wrapper                     sg\_rmsn

b2sum                                join                               sg\_rtpg

baobab                               journalctl                         sg\_safte

base32                               jsondiff                           sg\_sanitize

base64                               jsonpatch                          sg\_sat\_identify

basename                             json-patch-jsondiff                sg\_sat\_phy\_event

basenc                               jsonpointer                        sg\_sat\_read\_gplog

bash                                 json\_pp                            sg\_sat\_set\_features

bashbug                              jsonschema                         sg\_scan

bc                                   kbdinfo                            sg\_seek

bdftopcf                             kbd\_mode                           sg\_senddiag

bdftruncate                          kbxutil                            sg\_ses

bf\_compact                           keep-one-running                   sg\_ses\_microcode

bf\_compact-bdb                       kernel-install                     sg\_start

bf\_copy                              keyring                            sg\_stpg

bf\_copy-bdb                          kill                               sg\_stream\_ctl

bf\_tar                               killall                            sg\_sync

bf\_tar-bdb                           kmod                               sg\_test\_rwbuf

bitmap                               kmodsign                           sg\_timestamp

bluemoon                             l2ping                             sg\_turs

bluetoothctl                         l2test                             sg\_unmap

bluetooth-sendto                     landscape-sysinfo                  sg\_verify

bmtoa                                laptop-detect                      sg\_vpd

bogofilter                           last                               sg\_write\_buffer

bogofilter-bdb                       lastb                              sg\_write\_long

bogolexer                            lastlog                            sg\_write\_same

bogolexer-bdb                        lcf                                sg\_write\_verify

bogotune                             ld                                 sg\_write\_x

bogotune-bdb                         ld.bfd                             sg\_wr\_mode

bogoupgrade                          ldd                                sg\_xcopy

bogoupgrade-bdb                      ld.gold                            sg\_zone

bogoutil                             less                               sh

bogoutil-bdb                         lessecho                           sha1sum

boltctl                              lessfile                           sha224sum

bootctl                              lesskey                            sha256sum

broadwayd                            lesspipe                           sha384sum

browse                               lexgrog                            sha512sum

btattach                             libnetcfg                          shasum

btmgmt                               libreoffice                        shotwell

btmon                                libwacom-list-devices              showconsolefont

btrfs                                libwacom-list-local-devices        showkey

btrfsck                              libwacom-show-stylus               showrgb

btrfs-convert                        libwacom-update-db                 shred

btrfs-find-root                      link                               shuf

btrfs-image                          linux32                            simple-scan

btrfs-map-logical                    linux64                            size

btrfs-select-super                   linux-boot-prober                  skill

btrfstune                            linux-check-removal                slabtop

bunzip2                              linux-update-symlinks              sleep

busctl                               linux-version                      slogin

busybox                              listres                            smproxy

bwrap                                ln                                 snap

byobu                                lnstat                             snapctl

byobu-config                         loadkeys                           snapfuse

byobu-ctrl-a                         loadunimap                         snice

byobu-disable                        localc                             soelim

byobu-disable-prompt                 locale                             soffice

byobu-enable                         locale-check                       software-properties-gtk

byobu-enable-prompt                  localectl                          sort

byobu-export                         localedef                          sos

byobu-janitor                        lodraw                             sos-collector

byobu-keybindings                    loffice                            sosreport

byobu-launch                         lofromtemplate                     spa-acp-tool

byobu-launcher                       logger                             spa-inspect

byobu-launcher-install               login                              spa-json-dump

byobu-launcher-uninstall             loginctl                           spa-monitor

byobu-layout                         logname                            spa-resample

byobu-prompt                         loimpress                          spd-conf

byobu-quiet                          lomath                             spd-say

byobu-reconnect-sockets              look                               spdsend

byobu-screen                         loweb                              speaker-test

byobu-select-backend                 lowntfs-3g                         speech-dispatcher

byobu-select-profile                 lowriter                           splain

byobu-select-session                 lp\_solve                           split

byobu-shell                          ls                                 splitfont

byobu-silent                         lsattr                             sqfscat

byobu-status                         lsblk                              sqfstar

byobu-status-detail                  lsb\_release                        ss

byobu-tmux                           lscpu                              ssh

byobu-ugraph                         lshw                               ssh-add

byobu-ulevel                         lsinitramfs                        ssh-agent

bzcat                                lsipc                              ssh-argv0

bzcmp                                lslocks                            ssh-copy-id

bzdiff                               lslogins                           ssh-import-id

bzegrep                              lsmem                              ssh-import-id-gh

bzexe                                lsmod                              ssh-import-id-lp

bzfgrep                              lsns                               ssh-keygen

bzgrep                               lsof                               ssh-keyscan

bzip2                                lspci                              start-pulseaudio-x11

bzip2recover                         lspgpot                            startx

bzless                               lsusb                              stat

bzmore                               luit                               static-sh

captoinfo                            lwp-download                       stdbuf

caribou-preferences                  lwp-dump                           strace

cat                                  lwp-mirror                         strace-log-merge

catman                               lwp-request                        streamzip

cd-create-profile                    lzcat                              strings

cd-fix-profile                       lzcmp                              strip

cd-iccdump                           lzdiff                             stty

cd-it8                               lzegrep                            su

cdrdao                               lzfgrep                            sudo

c++filt                              lzgrep                             sudoedit

cftp3                                lzless                             sudoreplay

chacl                                lzma                               sum

chage                                lzmainfo                           sushi

chardet                              lzmore                             switcherooctl

chardetect                           mailmail3                          synaptic-pkexec

chattr                               mako-render                        sync

chcon                                man                                system-config-printer

check-language-support               mandb                              system-config-printer-applet

cheese                               manifest                           systemctl

chfn                                 manpath                            systemd

chgrp                                man-recode                         systemd-analyze

chmod                                mapscrn                            systemd-ask-password

choom                                mawk                               systemd-cat

chown                                mcookie                            systemd-cgls

chrome-gnome-shell                   md5sum                             systemd-cgtop

chrt                                 md5sum.textutils                   systemd-cryptenroll

chsh                                 mdig                               systemd-delta

chvt                                 mesa-overlay-control.py            systemd-detect-virt

ciptool                              mesg                               systemd-escape

ckbcomp                              migrate-pubring-from-classic-gpg   systemd-hwdb

ckeygen3                             mimeopen                           systemd-id128

cksum                                mimetype                           systemd-inhibit

clear                                mkdir                              systemd-machine-id-setup

clear\_console                        mkfifo                             systemd-mount

cloud-id                             mkfontdir                          systemd-notify

cloud-init                           mkfontscale                        systemd-path

cloud-init-per                       mk\_modmap                          systemd-run

cmp                                  mknod                              systemd-socket-activate

codepage                             mksquashfs                         systemd-stdio-bridge

col                                  mktemp                             systemd-sysext

col1                                 mmcli                              systemd-sysusers

col2                                 mokutil                            systemd-tmpfiles

col3                                 monitor-sensor                     systemd-tty-ask-password-agent

col4                                 more                               systemd-umount

col5                                 mount                              tabs

col6                                 mountpoint                         tac

col7                                 mt                                 tail

col8                                 mt-gnu                             tar

col9                                 mtr                                tasksel

colcrt                               mtr-packet                         taskset

colormgr                             mv                                 tbl

colrm                                namei                              tclsh

column                               nano                               tclsh8.6

comm                                 nautilus                           tcpdump

conch3                               nautilus-autorun-software          tee

corelist                             nawk                               telnet

cp                                   nc                                 telnet.netkit

cpan                                 nc.openbsd                         tempfile

cpan5.34-aarch64-linux-gnu           neqn                               test

cpio                                 netcat                             tic

cpp                                  netstat                            time

cpp-11                               networkctl                         timedatectl

c\_rehash                             networkd-dispatcher                timeout

crontab                              newgrp                             tkconch3

csplit                               NF                                 tload

ctail                                ngettext                           tmux

ctstat                               nice                               tnftp

curl                                 nisdomainname                      toc2cddb

cut                                  nl                                 toc2cue

cvt                                  nm                                 toe

cvtsudoers                           nm-applet                          top

dash                                 nmcli                              totem

date                                 nm-connection-editor               totem-video-thumbnailer

dbus-cleanup-sockets                 nm-online                          touch

dbus-daemon                          nmtui                              tput

dbus-monitor                         nmtui-connect                      tr

dbus-run-session                     nmtui-edit                         tracepath

dbus-send                            nmtui-hostname                     tracker3

dbus-update-activation-environment   nohup                              transmission-gtk

dbus-uuidgen                         nproc                              transset

dbxtool                              nroff                              trial3

dconf                                nsenter                            troff

dd                                   nslookup                           true

deallocvt                            nstat                              truncate

debconf                              nsupdate                           trust

debconf-apt-progress                 ntfs-3g                            tset

debconf-communicate                  ntfs-3g.probe                      tsort

debconf-copydb                       ntfscat                            tty

debconf-escape                       ntfscluster                        twist3

debconf-set-selections               ntfscmp                            twistd3

debconf-show                         ntfsdecrypt                        tzselect

debian-distro-info                   ntfsfallocate                      ua

deb-systemd-helper                   ntfsfix                            ubuntu-advantage

deb-systemd-invoke                   ntfsinfo                           ubuntu-bug

delpart                              ntfsls                             ubuntu-core-launcher

delv                                 ntfsmove                           ubuntu-distro-info

desktop-file-edit                    ntfsrecover                        ubuntu-drivers

desktop-file-install                 ntfssecaudit                       ubuntu-security-status

desktop-file-validate                ntfstruncate                       ucf

df                                   ntfsusermap                        ucfq

dfu-tool                             ntfswipe                           ucfr

dh\_bash-completion                   numfmt                             uclampset

dh\_installxmlcatalogs                nvidia-detector                    ucs2any

dh\_perl\_openssl                      obexctl                            udevadm

diff                                 objcopy                            udisksctl

diff3                                objdump                            ul

dig                                  oclock                             umax\_pp

dir                                  od                                 umount

dircolors                            oem-getlogs                        uname

dirmngr                              on\_ac\_power                        unattended-upgrade

dirmngr-client                       open                               unattended-upgrades

dirname                              openssl                            uncompress

distro-info                          openvt                             unexpand

dmesg                                orca                               unicode\_start

dnsdomainname                        orca-dm-wrapper                    unicode\_stop

domainname                           os-prober                          uniq

do-release-upgrade                   p11-kit                            unity-scope-loader

dpkg                                 pacat                              unlink

dpkg-deb                             pacmd                              unlzma

dpkg-divert                          pactl                              unmkinitramfs

dpkg-maintscript-helper              padsp                              unopkg

dpkg-query                           pager                              unshare

dpkg-realpath                        pa-info                            unsquashfs

dpkg-split                           pamon                              unxz

dpkg-statoverride                    paperconf                          unzip

dpkg-trigger                         paplay                             unzipsfx

du                                   parec                              unzstd

dumpkeys                             parecord                           update-alternatives

dwp                                  partx                              update-desktop-database

eatmydata                            passwd                             update-mime-database

ec2metadata                          paste                              upower

echo                                 pastebinit                         uptime

ed                                   pasuspender                        usb-devices

editor                               patch                              usbhid-dump

editres                              pathchk                            usbreset

efibootdump                          pax11publish                       users

efibootmgr                           pbget                              utmpdump

egrep                                pbput                              uuidgen

eject                                pbputs                             uuidparse

elfedit                              pdb3                               vcs-run

enc2xs                               pdb3.10                            vdir

encguess                             peekfd                             VGAuthService

enchant-2                            perl                               vi

enchant-lsmod-2                      perl5.34.0                         view

env                                  perl5.34-aarch64-linux-gnu         viewres

envsubst                             perlbug                            vigpg

eog                                  perldoc                            vim

eqn                                  perli11ndoc                        vim.basic

evince                               perlivp                            vimdiff

evince-previewer                     perlthanks                         vim.tiny

evince-thumbnailer                   pgrep                              vimtutor

evolution                            pic                                vmhgfs-fuse

ex                                   pico                               vmstat

expand                               piconv                             vm-support

expiry                               pidof                              vmtoolsd

expr                                 pidwait                            vmware-alias-import

factor                               pinentry                           vmware-checkvm

faillog                              pinentry-curses                    vmware-hgfsclient

fallocate                            pinentry-gnome3                    vmware-namespace-cmd

false                                pinentry-x11                       vmware-rpctool

fc-cache                             ping                               vmware-toolbox-cmd

fc-cat                               ping4                              vmware-vgauth-cmd

fc-conflist                          ping6                              vmware-vmblock-fuse

fc-list                              pinky                              vmware-xferlogs

fc-match                             pipewire                           w

fc-pattern                           pipewire-media-session             wall

fc-query                             pkaction                           watch

fc-scan                              pkcheck                            watchgnupg

fc-validate                          pkcon                              wc

fgconsole                            pkexec                             wdctl

fgrep                                pkill                              wget

file                                 pkmon                              whatis

file-roller                          pkttyagent                         whereis

finalrd                              pl2pm                              which

fincore                              pldd                               which.debianutils

find                                 plog                               whiptail

findmnt                              plymouth                           who

finger                               pmap                               whoami

firefox                              pod2html                           whoopsie

flock                                pod2man                            whoopsie-preferences

fmt                                  pod2text                           wifi-status

fold                                 pod2usage                          word-list-compress

fonttosfnt                           podchecker                         wpa\_passphrase

free                                 poff                               write

ftp                                  pollinate                          write.ul

funzip                               pon                                X

fuser                                POST                               X11

fusermount                           powerprofilesctl                   x11perf

fusermount3                          pr                                 x11perfcomp

fwupdagent                           precat                             xargs

fwupdate                             preconv                            xauth

fwupdmgr                             preunzip                           xbiff

fwupdtool                            prezip                             xbrlapi

gamma4scanimage                      prezip-bin                         xcalc

gapplication                         printenv                           xclipboard

gatttool                             printf                             xclock

gawk                                 prlimit                            xcmsdb

gcalccmd                             prove                              xconsole

gcm-import                           prtstat                            xcursorgen

gcm-inspect                          ps                                 xcutsel

gcm-picker                           psfaddtable                        xdg-dbus-proxy

gcm-viewer                           psfgettable                        xdg-desktop-icon

gcr-viewer                           psfstriptable                      xdg-desktop-menu

gdbus                                psfxtable                          xdg-email

gdialog                              pslog                              xdg-icon-resource

gdk-pixbuf-csource                   pstree                             xdg-mime

gdk-pixbuf-pixdata                   pstree.x11                         xdg-open

gdk-pixbuf-thumbnailer               ptar                               xdg-screensaver

gdmflexiserver                       ptardiff                           xdg-settings

gdm-screenshot                       ptargrep                           xdg-user-dir

gedit                                ptx                                xdg-user-dirs-gtk-update

geqn                                 pulseaudio                         xdg-user-dirs-update

GET                                  purge-old-kernels                  xditview

getconf                              pw-cat                             xdpyinfo

getent                               pw-cli                             xdriinfo

getfacl                              pwd                                xedit

getkeycodes                          pw-dot                             Xephyr

getopt                               pw-dsdplay                         xev

gettext                              pw-dump                            xeyes

gettext.sh                           pwdx                               xfd

ginstall-info                        pw-link                            xfontsel

gio                                  pw-loopback                        xgamma

gio-querymodules                     pw-metadata                        xgc

git                                  pw-mididump                        xhost

git-receive-pack                     pw-midiplay                        xinit

git-shell                            pw-midirecord                      xinput

git-upload-archive                   pw-mon                             xkbbell

git-upload-pack                      pw-play                            xkbcomp

gjs                                  pw-profiler                        xkbevd

gjs-console                          pw-record                          xkbprint

gkbd-keyboard-display                pw-reserve                         xkbvleds

glib-compile-schemas                 pw-top                             xkbwatch

gnome-calculator                     pw-v4l2                            xkeystone

gnome-calendar                       py3clean                           xkill

gnome-characters                     py3compile                         xload

gnome-clocks                         py3versions                        xlogo

gnome-contacts                       pybabel                            xlsatoms

gnome-control-center                 pybabel-python3                    xlsclients

gnome-disk-image-mounter             pydoc3                             xlsfonts

gnome-disks                          pydoc3.10                          xmag

gnome-extensions                     pygettext3                         xman

gnome-extensions-app                 pygettext3.10                      xmessage

gnome-font-viewer                    pyhtmlizer3                        xmodmap

gnome-help                           pyserial-miniterm                  xmore

gnome-keyring                        pyserial-ports                     Xorg

gnome-keyring-3                      python3                            xprop

gnome-keyring-daemon                 python3.10                         xrandr

gnome-language-selector              pzstd                              xrdb

gnome-logs                           quirks-handler                     xrefresh

gnome-maps                           ranlib                             x-session-manager

gnome-music                          rbash                              xset

gnome-session                        rcp                                xsetmode

gnome-session-classic                rctest                             xsetpointer

gnome-session-custom-session         rdma                               xsetroot

gnome-session-inhibit                readelf                            xsetwacom

gnome-session-properties             readlink                           xsm

gnome-session-quit                   realpath                           xstdcmap

gnome-shell                          red                                xsubpp

gnome-shell-extension-prefs          rendercheck                        x-terminal-emulator

gnome-shell-extension-tool           renice                             xvidtune

gnome-shell-perf-tool                rescan-scsi-bus.sh                 xvinfo

gnome-software                       reset                              Xwayland

gnome-sound-recorder                 resizepart                         xwd

gnome-system-monitor                 resolvectl                         xwininfo

gnome-terminal                       rev                                xwud

gnome-terminal.real                  rfcomm                             x-www-browser

gnome-terminal.wrapper               rgrep                              xxd

gnome-text-editor                    rhythmbox                          xz

gnome-thumbnail-font                 rhythmbox-client                   xzcat

gnome-todo                           rlogin                             xzcmp

gnome-tweaks                         rm                                 xzdiff

gnome-weather                        rmdir                              xzegrep

gnome-www-browser                    rnano                              xzfgrep

gnuplot                              routef                             xzgrep

gnuplot-qt                           routel                             xzless

gold                                 rrsync                             xzmore

gpasswd                              rsh                                yelp

gpg                                  rstart                             yes

gpg-agent                            rstartd                            ypdomainname

gpgcompose                           rsync                              zcat

gpgconf                              rsync-ssl                          zcmp

gpg-connect-agent                    rtstat                             zdiff

gpgparsemail                         runcon                             zdump

gpgsm                                run-one                            zegrep

gpgsplit                             run-one-constantly                 zenity

gpgtar                               run-one-until-failure              zfgrep

gpgv                                 run-one-until-success              zforce

gpg-wks-server                       run-parts                          zgrep

gpg-zip                              run-this-one                       zip

gpic                                 run-with-aspell                    zipcloak

gprof                                ruptime                            zipdetails

grdctl                               rview                              zipgrep

grep                                 rvim                               zipinfo

gresource                            rwho                               zipnote

groff                                rygel                              zipsplit

grog                                 sane-find-scanner                  zless

grops                                savelog                            zmore

grotty                               sbattach                           znew

groups                               sbkeysync                          zstd

growpart                             sbsiglist                          zstdcat

grub-editenv                         sbsign                             zstdgrep

grub-file                            sbvarsign                          zstdless

grub-fstest                          sbverify                           zstdmt

grub-glue-efi                        scandeps

ann@ann:/bin$ cd

ann@ann:~$ cd ..

ann@ann:/home$ cd

ann@ann:~$ cat > f1.txt

privet

^C

ann@ann:~$ ls

d1   f1.txt    set    Видео       Загрузки      Музыка         'Рабочий стол'

d2   gnuplot   snap   Документы   Изображения   Общедоступные   Шаблоны

ann@ann:~$ cat f1.txt

privet

ann@ann:~$ emacs f1.txt

ann@ann:~$ cat f1.txt

privet!!!!

ann@ann:~$ cp f1.txt f2.txt

ann@ann:~$ cat f1.txt f2.txt > f3.txt

ann@ann:~$ cat f3.txt

privet!!!!

privet!!!!

ann@ann:~$ rm f2.txt

ann@ann:~$ rm f3.txt

ann@ann:~$ mkdir lab

ann@ann:~$ mkdir course

ann@ann:~$ cp f1.txt lab

ann@ann:~$ cp f1.txt course

ann@ann:~$ rm f1.txt

ann@ann:~$ cd lab

ann@ann:~/lab$ rm f1.txt

ann@ann:~/lab$ cd ..

ann@ann:~$ rmdir lab

ann@ann:~$ rmdir course

rmdir: failed to remove 'course': Directory not empty

ann@ann:~$ cd course

ann@ann:~/course$ rm f1.txt

ann@ann:~/course$ cd ..

ann@ann:~$ rmdir course

ann@ann:~$ gnuplot

`	`G N U P L O T

`	`Version 5.4 patchlevel 2    last modified 2021-06-01

`	`Copyright (C) 1986-1993, 1998, 2004, 2007-2021

`	`Thomas Williams, Colin Kelley and many others

`	`gnuplot home:     http://www.gnuplot.info

`	`faq, bugs, etc:   type "help FAQ"

`	`immediate help:   type "help"  (plot window: hit 'h')

Terminal type is now 'qt'

gnuplot> plot sin(x)\*cos(x)

Warning: Ignoring XDG\_SESSION\_TYPE=wayland on Gnome. Use QT\_QPA\_PLATFORM=wayland to run on Wayland anyway.

gnuplot> set parametric

`	`dummy variable is t for curves, u/v for surfaces

gnuplot> set trange [0 to 2\*pi]

gnuplot> set xrange [-1 to 1]

gnuplot> set yrange [-1 to 1]

gnuplot> plot sin(t),cos(t)

gnuplot> set zrange [-1 to 1]

gnuplot> set urange [0 to 2\*pi]

gnuplot> set vrange [0 to 2\*pi]

gnuplot> unset hidden3d

gnuplot> splot sin(u)\*sin(v),sin(u)\*cos(v),cos(u)

gnuplot> unset noparametric

^

Unrecognized option.  See 'help unset'.

gnuplot> exit

ann@ann:~$ date

Пт 07 окт 2022 22:49:14 UTC

ann@ann:~$ ps

PID TTY          TIME CMD

4684 pts/0    00:00:00 bash

5773 pts/0    00:00:00 ps

ann@ann:~$ ls

d1   gnuplot   snap    Документы   Изображения   Общедоступные   Шаблоны

d2   set       Видео   Загрузки    Музыка       'Рабочий стол'

ann@ann:~$ uptime

22:49:38 up 22 min,  1 user,  load average: 0,25, 0,43, 0,33

```

## 9. Дневник отладки

Должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментария к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании отладки программы.

Долго не получилось установить Virtualbox, пришлось скачать UTM.

## 10. Замечания автора по существу работы:
```
ann@ann:~$ cat > 1.txt

privet

^C

ann@ann:~$ ls -l

total 48

- rw-rw-r-- 1 ann ann    7 окт  1 09:09  1.txt

drwxrwxr-x 3 ann ann 4096 сен 27 19:12  d1

drwxrwxr-x 2 ann ann 4096 сен 27 19:12  d2

- rw-rw-r-- 1 ann ann    0 сен 23 12:51  gnuplot
- rw-rw-r-- 1 ann ann    0 сен 23 15:04  set

drwx------ 4 ann ann 4096 окт  1 09:00  snap

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Видео

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Документы

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Загрузки

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Изображения

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Музыка

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Общедоступные

drwxr-xr-x 2 ann ann 4096 сен 23 13:25 'Рабочий стол'

drwxr-xr-x 2 ann ann 4096 сен 22 21:01  Шаблоны

ann@ann:~$ ls 1.txt -l

- rw-rw-r-- 1 ann ann 7 окт  1 09:09 1.txt

ann@ann:~$ chmod o+x 1.txt

ann@ann:~$ chmod u-x 1.txt

ann@ann:~$ ls 1.txt -l

- rw-rw-r-x 1 ann ann 7 окт  1 09:09 1.txt

ann@ann:~$ cd ~/

ann@ann:~$ man mkdir

ann@ann:~$ mkdir -p dir1/dir2/dir3

ann@ann:~$ ps -ef

UID          PID    PPID  C STIME TTY          TIME CMD

root           1       0  0 06:55 ?        00:00:01 /sbin/init

root           2       0  0 06:55 ?        00:00:00 [kthreadd]

root           3       2  0 06:55 ?        00:00:00 [rcu\_gp]

root           4       2  0 06:55 ?        00:00:00 [rcu\_par\_gp]

root           5       2  0 06:55 ?        00:00:00 [netns]

root           7       2  0 06:55 ?        00:00:00 [kworker/0:0H-events\_highpri

root           9       2  0 06:55 ?        00:00:00 [mm\_percpu\_wq]

root          10       2  0 06:55 ?        00:00:00 [rcu\_tasks\_rude\_]

root          11       2  0 06:55 ?        00:00:00 [rcu\_tasks\_trace]

root          12       2  0 06:55 ?        00:00:00 [ksoftirqd/0]

root          13       2  0 06:55 ?        00:00:01 [rcu\_sched]

root          14       2  0 06:55 ?        00:00:00 [migration/0]

root          15       2  0 06:55 ?        00:00:00 [idle\_inject/0]

root          17       2  0 06:55 ?        00:00:00 [cpuhp/0]

root          18       2  0 06:55 ?        00:00:00 [cpuhp/1]

root          19       2  0 06:55 ?        00:00:00 [idle\_inject/1]

root          20       2  0 06:55 ?        00:00:00 [migration/1]

root          21       2  0 06:55 ?        00:00:00 [ksoftirqd/1]

root          23       2  0 06:55 ?        00:00:00 [kworker/1:0H-events\_highpri

root          24       2  0 06:55 ?        00:00:00 [cpuhp/2]

root          25       2  0 06:55 ?        00:00:00 [idle\_inject/2]

root          26       2  0 06:55 ?        00:00:00 [migration/2]

root          27       2  0 06:55 ?        00:00:00 [ksoftirqd/2]

root          29       2  0 06:55 ?        00:00:00 [kworker/2:0H-events\_highpri

root          30       2  0 06:55 ?        00:00:00 [cpuhp/3]

root          31       2  0 06:55 ?        00:00:00 [idle\_inject/3]

root          32       2  0 06:55 ?        00:00:00 [migration/3]

root          33       2  0 06:55 ?        00:00:00 [ksoftirqd/3]

root          34       2  0 06:55 ?        00:00:00 [kworker/3:0-events]

root          35       2  0 06:55 ?        00:00:00 [kworker/3:0H-events\_highpri

root          36       2  0 06:55 ?        00:00:00 [kdevtmpfs]

root          37       2  0 06:55 ?        00:00:00 [inet\_frag\_wq]

root          41       2  0 06:55 ?        00:00:00 [kauditd]

root          42       2  0 06:55 ?        00:00:00 [khungtaskd]

root          43       2  0 06:55 ?        00:00:00 [oom\_reaper]

root          44       2  0 06:55 ?        00:00:00 [writeback]

root          45       2  0 06:55 ?        00:00:00 [kcompactd0]

root          46       2  0 06:55 ?        00:00:00 [ksmd]

root          47       2  0 06:55 ?        00:00:00 [khugepaged]

root          93       2  0 06:55 ?        00:00:00 [kintegrityd]

root          94       2  0 06:55 ?        00:00:00 [kblockd]

root          95       2  0 06:55 ?        00:00:00 [blkcg\_punt\_bio]

root          96       2  0 06:55 ?        00:00:00 [tpm\_dev\_wq]

root          97       2  0 06:55 ?        00:00:00 [ata\_sff]

root          98       2  0 06:55 ?        00:00:00 [md]

root          99       2  0 06:55 ?        00:00:00 [edac-poller]

root         100       2  0 06:55 ?        00:00:00 [devfreq\_wq]

root         101       2  0 06:55 ?        00:00:00 [watchdogd]

root         103       2  0 06:55 ?        00:00:00 [kworker/1:1H-kblockd]

root         104       2  0 06:55 ?        00:00:00 [kswapd0]

root         105       2  0 06:55 ?        00:00:00 [ecryptfs-kthrea]

root         107       2  0 06:55 ?        00:00:00 [kthrotld]

root         108       2  0 06:55 ?        00:00:00 [irq/49-ACPI:Ged]

root         109       2  0 06:55 ?        00:00:00 [acpi\_thermal\_pm]

root         111       2  0 06:55 ?        00:00:00 [kworker/0:1H-events\_highpri

root         112       2  0 06:55 ?        00:00:00 [mld]

root         113       2  0 06:55 ?        00:00:00 [ipv6\_addrconf]

root         122       2  0 06:55 ?        00:00:00 [kstrp]

root         125       2  0 06:55 ?        00:00:00 [zswap-shrink]

root         126       2  0 06:55 ?        00:00:00 [kworker/u9:0]

root         130       2  0 06:55 ?        00:00:00 [cryptd]

root         168       2  0 06:55 ?        00:00:00 [charger\_manager]

root         191       2  0 06:55 ?        00:00:00 [kworker/2:1H-events\_highpri

root         217       2  0 06:55 ?        00:00:00 [kworker/3:1H-kblockd]

root         218       2  0 06:55 ?        00:00:01 [kworker/1:2-events]

root         276       2  0 06:55 ?        00:00:00 [kdmflush]

root         303       2  0 06:55 ?        00:00:00 [raid5wq]

root         359       2  0 06:55 ?        00:00:00 [jbd2/dm-0-8]

root         360       2  0 06:55 ?        00:00:00 [ext4-rsv-conver]

root         396       2  0 06:55 ?        00:00:00 [hwrng]

root         435       1  0 06:55 ?        00:00:00 /lib/systemd/systemd-journal

root         463       2  0 06:55 ?        00:00:00 [ipmi-msghandler]

root         471       2  0 06:55 ?        00:00:00 [kaluad]

root         475       2  0 06:55 ?        00:00:00 [kmpath\_rdacd]

root         477       2  0 06:55 ?        00:00:00 [kmpathd]

root         478       2  0 06:55 ?        00:00:00 [kmpath\_handlerd]

root         479       1  0 06:55 ?        00:00:02 /sbin/multipathd -d -s

root         488       1  0 06:55 ?        00:00:00 /lib/systemd/systemd-udevd

root         573       2  0 06:55 ?        00:00:00 [scsi\_eh\_0]

root         575       2  0 06:55 ?        00:00:00 [scsi\_tmf\_0]

root         576       2  0 06:55 ?        00:00:02 [usb-storage]

root         587       2  0 06:55 ?        00:00:00 [uas]

root         621       2  0 06:55 ?        00:00:00 [jbd2/vda2-8]

root         628       2  0 06:55 ?        00:00:00 [ext4-rsv-conver]

systemd+     695       1  0 06:55 ?        00:00:00 /lib/systemd/systemd-timesyn

systemd+     756       1  0 06:55 ?        00:00:00 /lib/systemd/systemd-network

systemd+     758       1  0 06:55 ?        00:00:00 /lib/systemd/systemd-resolve

root         779       1  0 06:55 ?        00:00:00 /usr/libexec/accounts-daemon

root         780       1  0 06:55 ?        00:00:00 /usr/sbin/anacron -d -q -s

avahi        781       1  0 06:55 ?        00:00:00 avahi-daemon: running [ann.l

message+     782       1  0 06:55 ?        00:00:00 @dbus-daemon --system --addr

root         783       1  0 06:55 ?        00:00:00 /usr/sbin/NetworkManager --n

root         788       1  0 06:55 ?        00:00:00 /usr/sbin/irqbalance --foreg

root         789       1  0 06:55 ?        00:00:00 /usr/bin/python3 /usr/bin/ne

root         790       1  0 06:55 ?        00:00:00 /usr/libexec/polkitd --no-de

root         791       1  0 06:55 ?        00:00:00 /usr/libexec/power-profiles-

syslog       792       1  0 06:55 ?        00:00:00 /usr/sbin/rsyslogd -n -iNONE

root         793       1  0 06:55 ?        00:00:04 /usr/lib/snapd/snapd

root         794       1  0 06:55 ?        00:00:00 /usr/libexec/switcheroo-cont

root         795       1  0 06:55 ?        00:00:00 /lib/systemd/systemd-logind

root         796       1  0 06:55 ?        00:00:00 /usr/libexec/udisks2/udisksd

root         797       1  0 06:55 ?        00:00:00 /sbin/wpa\_supplicant -u -s -

avahi        800     781  0 06:55 ?        00:00:00 avahi-daemon: chroot helper

root         839       1  0 06:55 ?        00:00:00 /usr/bin/python3 /usr/share/

root         842       1  0 06:55 ?        00:00:00 /usr/sbin/ModemManager

root         899       1  0 06:55 ?        00:00:00 /usr/sbin/cron -f -P

root         914       1  0 06:55 ?        00:00:00 /sbin/agetty -o -p -- \u --k

rwhod        925       1  0 06:55 ?        00:00:00 /usr/sbin/rwhod -b

rwhod        926     925  0 06:55 ?        00:00:00 /usr/sbin/rwhod -b

root         928       1  0 06:55 ?        00:00:00 sshd: /usr/sbin/sshd -D [lis

root         931       1  0 06:55 ?        00:00:00 /usr/sbin/gdm3

rtkit       1113       1  0 06:55 ?        00:00:00 /usr/libexec/rtkit-daemon

root        1194       1  0 06:55 ?        00:00:00 /usr/libexec/upowerd

root        1235       1  0 06:55 ?        00:00:01 /usr/libexec/packagekitd

colord      1374       1  0 06:55 ?        00:00:00 /usr/libexec/colord

root        1441     931  0 06:55 ?        00:00:00 gdm-session-worker [pam/gdm-

ann         1451       1  0 06:55 ?        00:00:00 /lib/systemd/systemd --user

ann         1452    1451  0 06:55 ?        00:00:00 (sd-pam)

ann         1458    1451  0 06:55 ?        00:00:00 /usr/bin/pipewire

ann         1459    1451  0 06:55 ?        00:00:00 /usr/bin/pipewire-media-sess

ann         1460    1451  0 06:55 ?        00:00:00 /usr/bin/pulseaudio --daemon

ann         1465    1451  0 06:55 ?        00:00:00 /usr/bin/dbus-daemon --sessi

ann         1468       1  0 06:55 ?        00:00:00 /usr/bin/gnome-keyring-daemo

ann         1469    1451  0 06:55 ?        00:00:00 /usr/libexec/gvfsd

ann         1476    1451  0 06:55 ?        00:00:00 /usr/libexec/gvfsd-fuse /run

ann         1486    1441  0 06:55 tty2     00:00:00 /usr/libexec/gdm-wayland-ses

ann         1489    1486  0 06:55 tty2     00:00:00 /usr/libexec/gnome-session-b

ann         1512    1451  0 06:55 ?        00:00:01 /usr/libexec/tracker-miner-f

ann         1534    1451  0 06:55 ?        00:00:00 /usr/libexec/gnome-session-c

ann         1547    1451  0 06:55 ?        00:00:00 /usr/libexec/gnome-session-b

ann         1564    1547  0 06:55 ?        00:00:00 /usr/libexec/at-spi-bus-laun

ann         1568    1451  2 06:55 ?        00:03:10 /usr/bin/gnome-shell

ann         1576    1564  0 06:55 ?        00:00:00 /usr/bin/dbus-daemon --confi

ann         1577    1451  0 06:55 ?        00:00:00 /usr/libexec/gvfs-udisks2-vo

ann         1584    1451  0 06:55 ?        00:00:00 /usr/libexec/gvfs-afc-volume

ann         1593    1451  0 06:55 ?        00:00:00 /usr/libexec/gvfs-goa-volume

ann         1598    1451  0 06:55 ?        00:00:00 /usr/libexec/goa-daemon

ann         1615    1451  0 06:55 ?        00:00:00 /usr/libexec/goa-identity-se

ann         1622    1451  0 06:55 ?        00:00:00 /usr/libexec/gvfs-mtp-volume

ann         1627    1451  0 06:55 ?        00:00:00 /usr/libexec/gvfs-gphoto2-vo

ann         1639    1451  0 06:55 ?        00:00:00 /usr/libexec/xdg-permission-

ann         1641    1451  0 06:55 ?        00:00:00 /usr/libexec/gnome-shell-cal

ann         1650    1451  0 06:55 ?        00:00:00 /usr/libexec/evolution-sourc

ann         1657    1451  0 06:55 ?        00:00:00 /usr/libexec/evolution-calen

ann         1663    1451  0 06:55 ?        00:00:00 /usr/libexec/at-spi2-registr

ann         1664    1451  0 06:55 ?        00:00:00 /usr/bin/gjs /usr/share/gnom

ann         1670    1451  0 06:55 ?        00:00:00 sh -c /usr/bin/ibus-daemon -

ann         1671    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-a11y-settin

ann         1673    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-color

ann         1674    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-datetime

ann         1676    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-housekeepin

ann         1677    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-keyboard

ann         1678    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-media-keys

ann         1679    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-power

ann         1680    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-print-notif

ann         1681    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-rfkill

ann         1683    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-screensaver

ann         1685    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-sharing

ann         1689    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-smartcard

ann         1690    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-sound

ann         1691    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-wacom

ann         1698    1670  0 06:55 ?        00:00:05 /usr/bin/ibus-daemon --panel

ann         1713    1547  0 06:55 ?        00:00:00 /usr/libexec/gsd-disk-utilit

ann         1725    1547  0 06:55 ?        00:00:00 /usr/libexec/evolution-data-

ann         1741    1698  0 06:55 ?        00:00:00 /usr/libexec/ibus-dconf

ann         1750    1547  0 06:55 ?        00:00:01 /usr/bin/gnome-software --ga

ann         1753    1698  0 06:55 ?        00:00:01 /usr/libexec/ibus-extension-

ann         1761    1451  0 06:55 ?        00:00:00 /usr/libexec/ibus-portal

ann         1789    1451  0 06:55 ?        00:00:00 /usr/libexec/gsd-printer

ann         1834    1451  0 06:55 ?        00:00:00 /usr/libexec/dconf-service

ann         1835    1451  0 06:55 ?        00:00:00 /usr/libexec/evolution-addre

ann         1852    1698  0 06:55 ?        00:00:01 /usr/libexec/ibus-engine-sim

ann         1885    1451  0 06:55 ?        00:00:00 /usr/bin/gjs /usr/share/gnom

ann         2118    1451  0 06:56 ?        00:00:00 /usr/libexec/gvfsd-metadata

ann         2306    1568  0 07:05 ?        00:00:00 /usr/bin/Xwayland :0 -rootle

ann         2310    1451  0 07:05 ?        00:00:00 /usr/libexec/gsd-xsettings

ann         2335    1451  0 07:05 ?        00:00:00 /usr/libexec/xdg-desktop-por

ann         2342    1451  0 07:05 ?        00:00:00 /usr/libexec/xdg-document-po

root        2350    2342  0 07:05 ?        00:00:00 fusermount3 -o rw,nosuid,nod

ann         2358    1451  0 07:05 ?        00:00:00 /usr/libexec/xdg-desktop-por

ann         2366    1451  0 07:05 ?        00:00:00 /usr/libexec/ibus-x11

ann         2377    1451  0 07:05 ?        00:00:00 /usr/libexec/xdg-desktop-por

root        2491       2  0 07:11 ?        00:00:00 [kworker/2:0-events]

root        2601       2  0 07:43 ?        00:00:00 [kworker/2:2-inet\_frag\_wq]

root        2954       2  0 08:47 ?        00:00:00 [kworker/u8:2-flush-253:0]

root        3005       2  0 08:55 ?        00:00:00 [kworker/0:3-events]

ann         3358    1451  0 09:00 ?        00:00:00 /usr/bin/snap userd

root        4085       2  0 09:00 ?        00:00:00 [kworker/u8:0-events\_unbound

root        4089       2  0 09:00 ?        00:00:00 [kworker/1:1-events]

root        4457       2  0 09:01 ?        00:00:00 [kworker/0:0-mm\_percpu\_wq]

ann         4501    1469  0 09:04 ?        00:00:00 /usr/libexec/gvfsd-trash --s

ann         4530    1469  0 09:04 ?        00:00:00 /usr/libexec/gvfsd-network -

ann         4547    1469  0 09:04 ?        00:00:00 /usr/libexec/gvfsd-dnssd --s

root        4564       2  0 09:05 ?        00:00:00 [kworker/3:3-events]

root        4567       2  0 09:05 ?        00:00:00 [kworker/2:1-events]

root        4568       2  0 09:05 ?        00:00:00 [kworker/u8:1-events\_unbound

root        4594       2  0 09:06 ?        00:00:00 [kworker/2:3-events]

ann         4611    1451  0 09:06 ?        00:00:01 /usr/libexec/gnome-terminal-

ann         4655    4611  0 09:06 pts/0    00:00:00 bash

root        4662       2  0 09:06 ?        00:00:00 [kworker/0:1-events]

root        4666       2  0 09:07 ?        00:00:00 [kworker/1:0-mm\_percpu\_wq]

ann         4746    1451  0 09:10 ?        00:00:00 /usr/libexec/tracker-extract

ann         4751    4655  0 09:11 pts/0    00:00:00 ps -ef

ann@ann:~$ vim

[1]+  Stopped                 vim

ann@ann:~$ jobs

[1]+  Stopped                 vim

ann@ann:~$ vim

[2]+  Stopped                 vim

ann@ann:~$ jobs

[1]-  Stopped                 vim

[2]+  Stopped                 vim

ann@ann:~$ kill %1

ann@ann:~$ jobs

[1]+  Stopped                 vim

[2]-  Stopped                 vim

ann@ann:~$ jobs

[1]+  Stopped                 vim

[2]-  Stopped                 vim

ann@ann:~$ jobs

[1]+  Stopped                 vim

[2]-  Stopped                 vim

ann@ann:~$ jobs

[1]+  Stopped                 vim

[2]-  Stopped                 vim

ann@ann:~$ kill -9 %1

[1]+  Stopped                 vim

ann@ann:~$ kill -9 %1

bash: kill: (7904) - No such process

[1]+  Killed                  vim

ann@ann:~$ kill -9 %2

[2]+  Stopped                 vim

ann@ann:~$ jobs

[2]+  Killed                  vim

ann@ann:~$ ps -eo pid,comm,vsz,tty

PID COMMAND            VSZ TT

1. systemd         168284 ?
1. kthreadd             0 ?
1. rcu\_gp               0 ?
1. rcu\_par\_gp           0 ?
1. netns                0 ?

7 kworker/0:0H-ev      0 ?

9 mm\_percpu\_wq         0 ?

10 rcu\_tasks\_rude\_      0 ?

11 rcu\_tasks\_trace      0 ?

12 ksoftirqd/0          0 ?

13 rcu\_sched            0 ?

14 migration/0          0 ?

15 idle\_inject/0        0 ?

17 cpuhp/0              0 ?

18 cpuhp/1              0 ?

19 idle\_inject/1        0 ?

20 migration/1          0 ?

21 ksoftirqd/1          0 ?

23 kworker/1:0H-ev      0 ?

24 cpuhp/2              0 ?

25 idle\_inject/2        0 ?

26 migration/2          0 ?

27 ksoftirqd/2          0 ?

29 kworker/2:0H-ev      0 ?

30 cpuhp/3              0 ?

31 idle\_inject/3        0 ?

32 migration/3          0 ?

33 ksoftirqd/3          0 ?

34 kworker/3:0-eve      0 ?

35 kworker/3:0H-ev      0 ?

36 kdevtmpfs            0 ?

37 inet\_frag\_wq         0 ?

41 kauditd              0 ?

42 khungtaskd           0 ?

43 oom\_reaper           0 ?

44 writeback            0 ?

45 kcompactd0           0 ?

46 ksmd                 0 ?

47 khugepaged           0 ?

93 kintegrityd          0 ?

94 kblockd              0 ?

95 blkcg\_punt\_bio       0 ?

96 tpm\_dev\_wq           0 ?

97 ata\_sff              0 ?

98 md                   0 ?

99 edac-poller          0 ?

100 devfreq\_wq           0 ?

101 watchdogd            0 ?

103 kworker/1:1H-ev      0 ?

104 kswapd0              0 ?

105 ecryptfs-kthrea      0 ?

107 kthrotld             0 ?

108 irq/49-ACPI:Ged      0 ?

109 acpi\_thermal\_pm      0 ?

111 kworker/0:1H-ev      0 ?

112 mld                  0 ?

113 ipv6\_addrconf        0 ?

122 kstrp                0 ?

125 zswap-shrink         0 ?

126 kworker/u9:0         0 ?

130 cryptd               0 ?

168 charger\_manager      0 ?

191 kworker/2:1H-kb      0 ?

217 kworker/3:1H-ev      0 ?

276 kdmflush             0 ?

303 raid5wq              0 ?

359 jbd2/dm-0-8          0 ?

360 ext4-rsv-conver      0 ?

396 hwrng                0 ?

435 systemd-journal  65064 ?

463 ipmi-msghandler      0 ?

471 kaluad               0 ?

475 kmpath\_rdacd         0 ?

477 kmpathd              0 ?

478 kmpath\_handlerd      0 ?

479 multipathd      289668 ?

488 systemd-udevd    26548 ?

573 scsi\_eh\_0            0 ?

575 scsi\_tmf\_0           0 ?

576 usb-storage          0 ?

587 uas                  0 ?

621 jbd2/vda2-8          0 ?

628 ext4-rsv-conver      0 ?

695 systemd-timesyn  88724 ?

756 systemd-network  16260 ?

758 systemd-resolve  25200 ?

779 accounts-daemon 237184 ?

780 anacron           5192 ?

781 avahi-daemon      7956 ?

782 dbus-daemon      11316 ?

783 NetworkManager  259468 ?

788 irqbalance       82116 ?

789 networkd-dispat  39100 ?

790 polkitd         236892 ?

791 power-profiles- 237372 ?

792 rsyslogd        222032 ?

793 snapd           1169204 ?

794 switcheroo-cont 233748 ?

795 systemd-logind   15672 ?

796 udisksd         394008 ?

797 wpa\_supplicant   15252 ?

800 avahi-daemon      7692 ?

839 unattended-upgr 116164 ?

842 ModemManager    319752 ?

899 cron              6520 ?

914 agetty            5216 ?

925 rwhod             2200 ?

926 rwhod             2200 ?

928 sshd             15156 ?

931 gdm3            238844 ?

1113 rtkit-daemon    153484 ?

1194 upowerd         239468 ?

1235 packagekitd     372300 ?

1374 colord          243160 ?

1441 gdm-session-wor 316840 ?

1451 systemd          17964 ?

1452 (sd-pam)        171120 ?

1458 pipewire         37296 ?

1459 pipewire-media-  20952 ?

1460 pulseaudio      1151344 ?

1465 dbus-daemon       9816 ?

1468 gnome-keyring-d 238056 ?

1469 gvfsd           237948 ?

1476 gvfsd-fuse      381020 ?

1486 gdm-wayland-ses 159588 tty2

1489 gnome-session-b 222860 tty2

1512 tracker-miner-f 634388 ?

1534 gnome-session-c  88936 ?

1547 gnome-session-b 658528 ?

1564 at-spi-bus-laun 309828 ?

1568 gnome-shell     4951976 ?

1576 dbus-daemon       8696 ?

1577 gvfs-udisks2-vo 313512 ?

1584 gvfs-afc-volume 312368 ?

1593 gvfs-goa-volume 233944 ?

1598 goa-daemon      626512 ?

1615 goa-identity-se 338400 ?

1622 gvfs-mtp-volume 233820 ?

1627 gvfs-gphoto2-vo 235136 ?

1639 xdg-permission- 233400 ?

1641 gnome-shell-cal 584868 ?

1650 evolution-sourc 1074244 ?

1657 evolution-calen 843084 ?

1663 at-spi2-registr 162972 ?

1664 gjs             2666540 ?

1670 sh                2308 ?

1671 gsd-a11y-settin 307932 ?

1673 gsd-color       534700 ?

1674 gsd-datetime    375992 ?

1676 gsd-housekeepin 309504 ?

1677 gsd-keyboard    338224 ?

1678 gsd-media-keys  715236 ?

1679 gsd-power       448788 ?

1680 gsd-print-notif 321708 ?

1681 gsd-rfkill      455516 ?

1683 gsd-screensaver 233652 ?

1685 gsd-sharing     463948 ?

1689 gsd-smartcard   457616 ?

1690 gsd-sound       317612 ?

1691 gsd-wacom       338980 ?

1698 ibus-daemon     312312 ?

1713 gsd-disk-utilit 232160 ?

1725 evolution-alarm 821008 ?

1741 ibus-dconf      234776 ?

1750 gnome-software  648348 ?

1753 ibus-extension- 343208 ?

1761 ibus-portal     234660 ?

1789 gsd-printer     342648 ?

1834 dconf-service   156764 ?

1835 evolution-addre 746288 ?

1852 ibus-engine-sim 160824 ?

1885 gjs             2666656 ?

2118 gvfsd-metadata  160368 ?

2306 Xwayland        190304 ?

2310 gsd-xsettings   496420 ?

2335 xdg-desktop-por 622232 ?

2342 xdg-document-po 534336 ?

2350 fusermount3       2212 ?

2358 xdg-desktop-por 661760 ?

2366 ibus-x11        190668 ?

2377 xdg-desktop-por 338020 ?

3358 snap            719152 ?

4085 kworker/u8:0-fl      0 ?

4501 gvfsd-trash     312144 ?

4530 gvfsd-network   386284 ?

4547 gvfsd-dnssd     314596 ?

4567 kworker/2:1-cgr      0 ?

4568 kworker/u8:1-fl      0 ?

4611 gnome-terminal- 547156 ?

4655 bash              8180 pts/0

4662 kworker/0:1-eve      0 ?

4666 kworker/1:0-eve      0 ?

4794 kworker/3:1-eve      0 ?

4807 kworker/u8:3-ev      0 ?

6155 kworker/u8:4-fl      0 ?

6758 kworker/2:2-eve      0 ?

7209 kworker/1:2-eve      0 ?

7375 kworker/0:3-eve      0 ?

7376 bash              8180 pts/1

7386 firefox         2730788 pts/1

7561 Socket Process  191020 pts/1

7591 Privileged Cont 2398504 pts/1

7690 WebExtensions   2408848 pts/1

7842 Web Content     2368624 pts/1

7845 Web Content     2368624 pts/1

7849 Web Content     2368624 pts/1

7888 kworker/u8:2-ev      0 ?

7894 kworker/3:2-eve      0 ?

7908 kworker/0:0-eve      0 ?

7912 ps                9428 pts/0

ann@ann:~$ ps -eo pid,comm,vsz,tty | grep "firefox"

7386 firefox         2730852 pts/1

ann@ann:~$ ps -eo pid,comm,vsz,tty | grep "firefox" | grep "pts/1"

7386 firefox         2730852 pts/1

ann@ann:~$ ps -eo pid,comm,vsz,tty | grep "firefox" | grep "pts/1" | awk '$3>1000{print $1}'

7386

ann@ann:~$ ps -eo pid,comm,vsz,tty | grep "firefox" | grep "pts/1" | awk '$3>1000{print $1}'

7386

ann@ann:~$ ps -eo pid,comm,vsz,tty | grep "firefox" | grep "pts/1" | awk '$3>1000{print $1}'

7386

7938

ann@ann:~$ ps -eo pid,comm,vsz,tty | grep "firefox" | grep "pts/1" | awk '$3>1000{print $1}' | xargs kill -9

ann@ann:~$ ps -eo pid,comm,vsz,tty | grep "firefox" | grep "pts/1" | awk '$3>1000{print $1}'

8077

8587

ann@ann:~$ firefox

Gtk-Message: 09:40:53.379: Failed to load module "canberra-gtk-module"

Gtk-Message: 09:40:53.380: Failed to load module "canberra-gtk-module"

Missing chrome or resource URL: resource://gre/modules/UpdateListener.sys.mjs

^Z

[1]+  Stopped                 firefox

ann@ann:~$ ps -eo pid,comm,vsz,tty

PID COMMAND            VSZ TT

1. systemd         168284 ?
1. kthreadd             0 ?
1. rcu\_gp               0 ?
1. rcu\_par\_gp           0 ?
1. netns                0 ?

7 kworker/0:0H-ev      0 ?

9 mm\_percpu\_wq         0 ?

10 rcu\_tasks\_rude\_      0 ?

11 rcu\_tasks\_trace      0 ?

12 ksoftirqd/0          0 ?

13 rcu\_sched            0 ?

14 migration/0          0 ?

15 idle\_inject/0        0 ?

17 cpuhp/0              0 ?

18 cpuhp/1              0 ?

19 idle\_inject/1        0 ?

20 migration/1          0 ?

21 ksoftirqd/1          0 ?

23 kworker/1:0H-ev      0 ?

24 cpuhp/2              0 ?

25 idle\_inject/2        0 ?

26 migration/2          0 ?

27 ksoftirqd/2          0 ?

29 kworker/2:0H-ev      0 ?

30 cpuhp/3              0 ?

31 idle\_inject/3        0 ?

32 migration/3          0 ?

33 ksoftirqd/3          0 ?

35 kworker/3:0H-ev      0 ?

36 kdevtmpfs            0 ?

37 inet\_frag\_wq         0 ?

41 kauditd              0 ?

42 khungtaskd           0 ?

43 oom\_reaper           0 ?

44 writeback            0 ?

45 kcompactd0           0 ?

46 ksmd                 0 ?

47 khugepaged           0 ?

93 kintegrityd          0 ?

94 kblockd              0 ?

95 blkcg\_punt\_bio       0 ?

96 tpm\_dev\_wq           0 ?

97 ata\_sff              0 ?

98 md                   0 ?

99 edac-poller          0 ?

100 devfreq\_wq           0 ?

101 watchdogd            0 ?

103 kworker/1:1H-ev      0 ?

104 kswapd0              0 ?

105 ecryptfs-kthrea      0 ?

107 kthrotld             0 ?

108 irq/49-ACPI:Ged      0 ?

109 acpi\_thermal\_pm      0 ?

111 kworker/0:1H-ev      0 ?

112 mld                  0 ?

113 ipv6\_addrconf        0 ?

122 kstrp                0 ?

125 zswap-shrink         0 ?

126 kworker/u9:0         0 ?

130 cryptd               0 ?

168 charger\_manager      0 ?

191 kworker/2:1H-kb      0 ?

217 kworker/3:1H-ev      0 ?

276 kdmflush             0 ?

303 raid5wq              0 ?

359 jbd2/dm-0-8          0 ?

360 ext4-rsv-conver      0 ?

396 hwrng                0 ?

435 systemd-journal  65064 ?

463 ipmi-msghandler      0 ?

471 kaluad               0 ?

475 kmpath\_rdacd         0 ?

477 kmpathd              0 ?

478 kmpath\_handlerd      0 ?

479 multipathd      289668 ?

488 systemd-udevd    26548 ?

573 scsi\_eh\_0            0 ?

575 scsi\_tmf\_0           0 ?

576 usb-storage          0 ?

587 uas                  0 ?

621 jbd2/vda2-8          0 ?

628 ext4-rsv-conver      0 ?

695 systemd-timesyn  88724 ?

756 systemd-network  16260 ?

758 systemd-resolve  25200 ?

779 accounts-daemon 237184 ?

780 anacron           5192 ?

781 avahi-daemon      7956 ?

782 dbus-daemon      11316 ?

783 NetworkManager  259468 ?

788 irqbalance       82116 ?

789 networkd-dispat  39100 ?

790 polkitd         236892 ?

791 power-profiles- 237372 ?

792 rsyslogd        222032 ?

793 snapd           1169204 ?

794 switcheroo-cont 233748 ?

795 systemd-logind   15672 ?

796 udisksd         394008 ?

797 wpa\_supplicant   15252 ?

800 avahi-daemon      7692 ?

839 unattended-upgr 116164 ?

842 ModemManager    319752 ?

899 cron              6520 ?

914 agetty            5216 ?

925 rwhod             2200 ?

926 rwhod             2200 ?

928 sshd             15156 ?

931 gdm3            238844 ?

1113 rtkit-daemon    153484 ?

1194 upowerd         239468 ?

1235 packagekitd     372300 ?

1374 colord          243160 ?

1441 gdm-session-wor 316840 ?

1451 systemd          17964 ?

1452 (sd-pam)        171120 ?

1458 pipewire         37296 ?

1459 pipewire-media-  20952 ?

1460 pulseaudio      1151344 ?

1465 dbus-daemon       9816 ?

1468 gnome-keyring-d 238056 ?

1469 gvfsd           237948 ?

1476 gvfsd-fuse      381020 ?

1486 gdm-wayland-ses 159588 tty2

1489 gnome-session-b 222860 tty2

1512 tracker-miner-f 634388 ?

1534 gnome-session-c  88936 ?

1547 gnome-session-b 658528 ?

1564 at-spi-bus-laun 309828 ?

1568 gnome-shell     4956196 ?

1576 dbus-daemon       8696 ?

1577 gvfs-udisks2-vo 313512 ?

1584 gvfs-afc-volume 312368 ?

1593 gvfs-goa-volume 233944 ?

1598 goa-daemon      626512 ?

1615 goa-identity-se 338400 ?

1622 gvfs-mtp-volume 233820 ?

1627 gvfs-gphoto2-vo 235136 ?

1639 xdg-permission- 233400 ?

1641 gnome-shell-cal 584868 ?

1650 evolution-sourc 1074244 ?

1657 evolution-calen 843084 ?

1663 at-spi2-registr 162972 ?

1664 gjs             2666540 ?

1670 sh                2308 ?

1671 gsd-a11y-settin 307932 ?

1673 gsd-color       534700 ?

1674 gsd-datetime    375992 ?

1676 gsd-housekeepin 309504 ?

1677 gsd-keyboard    338224 ?

1678 gsd-media-keys  715236 ?

1679 gsd-power       448788 ?

1680 gsd-print-notif 321708 ?

1681 gsd-rfkill      455516 ?

1683 gsd-screensaver 233652 ?

1685 gsd-sharing     463948 ?

1689 gsd-smartcard   457616 ?

1690 gsd-sound       317612 ?

1691 gsd-wacom       338980 ?

1698 ibus-daemon     312312 ?

1713 gsd-disk-utilit 232160 ?

1725 evolution-alarm 821008 ?

1741 ibus-dconf      234776 ?

1750 gnome-software  648348 ?

1753 ibus-extension- 343208 ?

1761 ibus-portal     234660 ?

1789 gsd-printer     342648 ?

1834 dconf-service   156764 ?

1835 evolution-addre 746288 ?

1852 ibus-engine-sim 160824 ?

1885 gjs             2666656 ?

2118 gvfsd-metadata  160368 ?

2306 Xwayland        191360 ?

2310 gsd-xsettings   496420 ?

2335 xdg-desktop-por 622232 ?

2342 xdg-document-po 534336 ?

2350 fusermount3       2212 ?

2358 xdg-desktop-por 661760 ?

2366 ibus-x11        190668 ?

2377 xdg-desktop-por 338020 ?

3358 snap            719152 ?

4085 kworker/u8:0-ev      0 ?

4501 gvfsd-trash     312144 ?

4530 gvfsd-network   386284 ?

4547 gvfsd-dnssd     314596 ?

4611 gnome-terminal- 548032 ?

4655 bash              8180 pts/0

4666 kworker/1:0-mm\_      0 ?

7376 bash              8180 pts/1

7888 kworker/u8:2-ev      0 ?

7908 kworker/0:0-eve      0 ?

8073 kworker/1:1-eve      0 ?

8074 kworker/u8:1-ev      0 ?

8075 kworker/2:0-eve      0 ?

8076 kworker/3:0-mm\_      0 ?

8803 kworker/2:1-eve      0 ?

8805 kworker/3:2          0 ?

8806 kworker/0:1-eve      0 ?

8822 firefox         2835388 pts/0

8998 Socket Process  191020 pts/0

9032 Privileged Cont 2400644 pts/0

9126 WebExtensions   2410460 pts/0

9283 Web Content     2377244 pts/0

9286 Web Content     2377244 pts/0

9290 Web Content     2377240 pts/0

9345 kworker/1:2-eve      0 ?

9346 kworker/0:2          0 ?

9347 ps                9428 pts/0

ann@ann:~$ ps -eo pid,comm,vsz,tty | grep "firefox"

8822 firefox         2835388 pts/0

ann@ann:~$ ps -eo pid,comm,vsz,tty | grep "firefox" | grep "pts/1"

ann@ann:~$ ps -eo pid,comm,vsz,tty | grep "firefox" | grep "pts/1" | awk '$3>1000{print $1}' | xargs kill -9

Usage:

kill [options] <pid> [...]

Options:

<pid> [...]            send signal to every <pid> listed

-<signal>, -s, --signal <signal>

specify the <signal> to be sent

- q, --queue <value>    integer value to be sent with the signal
- l, --list=[<signal>]  list all signal names, or convert one to a name
- L, --table            list all signal names in a nice table

- h, --help     display this help and exit
- V, --version  output version information and exit

For more details see kill(1).

ann@ann:~$ firefox

Gtk-Message: 09:45:06.363: Failed to load module "canberra-gtk-module"

Gtk-Message: 09:45:06.364: Failed to load module "canberra-gtk-module"

[1]+  Killed                  firefox

ann@ann:~$ ps -eo pid,comm,vsz,tty |grep "firefox"

11256 firefox         2765780 pts/0

11833 firefox         193456 pts/0

ann@ann:~$ ps -eo pid,comm,vsz,tty |grep "firefox" | grep "pts/0"

11256 firefox         2765780 pts/0

11833 firefox         193456 pts/0

ann@ann:~$ ps -eo pid,comm,vsz,tty |grep "firefox" | grep "pts/0" | awk '$3>100{print $1}' | xargs kill -9

ann@ann:~$ jobs

[1]-  Killed                  firefox

[2]+  Killed                  firefox


[2]+  Stopped                 vim

ann@ann:~$ gnuplot

`	`G N U P L O T

`	`Version 5.4 patchlevel 2    last modified 2021-06-01

`	`Copyright (C) 1986-1993, 1998, 2004, 2007-2021

`	`Thomas Williams, Colin Kelley and many others

`	`gnuplot home:     http://www.gnuplot.info

`	`faq, bugs, etc:   type "help FAQ"

`	`immediate help:   type "help"  (plot window: hit 'h')

Terminal type is now 'qt'

gnuplot> set parametric

`	`dummy variable is t for curves, u/v for surfaces

gnuplot> set urange[0 to 2\*pi]

gnuplot> set vrange[0 to 2\*pi]

gnuplot> unset hidden3d

gnuplot> splot sin(u)\*cos(u),sin(v)\*cos(v),cos(u)

```
## 11. Выводы

Были преобретены первоначальные навыки по работе с OC UNIX. Были изучены команды для перемещения по директориям, для создания, копирования, вставки, редактирования, удаления файлов. Также были изучены команды для манипуляций с папками. Была изучена утилита gnuplot, с ее помощью получилось построить сферу и другие фигуры и графики. Было заложено начало по изучению OC UNIX.

Недочёты при выполнении задания могут быть выполнены следующим образом: использовать интерпретаторы.


Подпись студета:

