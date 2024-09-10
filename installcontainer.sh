# Definir variáveis
URL="http://cdimage.ubuntu.com/ubuntu-base/releases/20.04/release/ubuntu-base-20.04.3-base-amd64.tar.gz"
DIR="container"
TAR_FILE="ubuntu-base.tar.gz"


# Verificar se o script está sendo executado como root
if [[ $EUID -ne 0 ]]; then
   echo "these script must be executed as root"
   exit 1
fi

echo ""
echo "delet dependencies"
mkdir src/dependencies
echo ""
 sh install_dependencies.sh

echo ""
echo ""
echo ""
#resouvendo problemas de montagem anterior
umount "$DIR/proc"
umount "$DIR/sys"
umount "$DIR/dev/pts"
umount "$DIR/dev"
umount "$DIR"


#!/bin/bash
echo "deletando container antigo"
sudo rm -rf $DIR

echo "Baixando o sistema de arquivos mínimo do Ubuntu..."
wget -O "$TAR_FILE" "$URL"

# Verificar se o download foi bem-sucedido
if [ $? -ne 0 ]; then
    echo "Falha ao baixar o arquivo"
    exit 1
fi

# Criar o diretório onde o sistema de arquivos será montado
echo "Criando diretório $DIR..."
mkdir -p "$DIR"

# Descompactar o sistema de arquivos
echo "Descompactando o sistema de arquivos..."
tar -xzf "$TAR_FILE" -C "$DIR"

#da acesso a internet
 cp -L /etc/resolv.conf ./$DIR/etc/


# Montar os sistemas de arquivos necessários para o chroot
echo "Montando sistemas de arquivos necessários..."
mount --bind /proc "$DIR/proc"
mount --bind /sys "$DIR/sys"
mount --bind /dev "$DIR/dev"
mount --bind /dev/pts "$DIR/dev/pts"


echo "Instalando o projeto"
chroot $DIR /bin/bash -c 'apt update'
chroot $DIR /bin/bash -c 'DEBIAN_FRONTEND=noninteractive apt install -y gcc build-essential'
#install ix86 gcc 
chroot $DIR /bin/bash -c 'apt install -y gcc-multilib'


# Após sair do chroot, desmontar os sistemas de arquivos
echo "Desmontando sistemas de arquivos..."
umount "$DIR/proc"
umount "$DIR/sys"
umount "$DIR/dev/pts"
umount "$DIR/dev"
umount "$DIR"

sudo rm  $DIR/etc/resolv.conf

echo "Processo concluído."