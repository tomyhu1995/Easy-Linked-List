# Copyright (C) 2017 by Hsien Wen, Hu
#
# Makefile for sample_linked_list
#
#
# Author: Hsien-Wen, Hu
#
# Date: 2017/4/15
#

CC = gcc

CFLAGS += -Wall
CFLAGS += -g

EXE_NAME = Sample_linked_list

INC =
INC += -I../

SRC = 
SRC += ../linked_list

SRC_FILES = ${addsuffix .c, ${SRC}}
OBJ_FILES = ${addsuffix .o, ${SRC}}

MAIN = Sample_linked_list.c

all: ${EXE_NAME}

${EXE_NAME}: ${OBJ_FILES}
	${CC} ${CFLAGS} ${INC} ${MAIN} ${OBJ_FILES} -o $@
${OBJ_FILES} : %.o : %.c
	${CC} ${CFLAGS} -c ${INC} $< -o $@
clean:
	rm -rf ${OBJ_FILES} ${EXE_NAME}