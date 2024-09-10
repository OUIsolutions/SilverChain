


# Definir variáveis
DIR="container"
SRC="src"
COMANDO="gcc $SRC/main.c -o silverchain.out && x86_64-w64-mingw32-gcc $SRC/main.c -o silverchain.exe"


#resouvendo problemas de montagem anterior
umount "$DIR/proc"
umount "$DIR/sys"
umount "$DIR/dev/pts"
umount "$DIR/dev"
umount "$DIR"


# Verificar se o script está sendo executado como root
if [[ $EUID -ne 0 ]]; then
   echo "these script must be executed as root"
   exit 1
fi


#da acesso a internet (nescessário se seu app vai usar internet emquanto roda)
sudo cp -L /etc/resolv.conf ./$DIR/etc/
sudo mkdir ./$DIR/$PROJECTS
sudo cp -r ./$SRC ./static ./$DIR/


# Montar os sistemas de arquivos necessários para o chroot
echo "mounting the file system..."
mount --bind /proc "$DIR/proc"
mount --bind /sys "$DIR/sys"
mount --bind /dev "$DIR/dev"
mount --bind /dev/pts "$DIR/dev/pts"

xhost +local:

#starta o app
chroot $DIR /bin/bash -c  "$COMANDO"


# Após sair do chroot, desmontar os sistemas de arquivos
echo "Unmounting the file system..."
umount "$DIR/proc"
umount "$DIR/sys"
umount "$DIR/dev/pts"
umount "$DIR/dev"
umount "$DIR"

#Remove o arquivo de interent do container
sudo rm  $DIR/etc/resolv.conf

echo "movendo resultado para pasta"
mv $DIR/silverchain.out .
mv $DIR/silverchain.exe .
echo "process finished."