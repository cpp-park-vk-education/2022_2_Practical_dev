#pragma once

#include "users/users.hpp"

class Comment;

class CommentServiceInterface {
 public:
    virtual User get(Comment &comment) = 0;
    virtual User add(Comment &comment) = 0;
    virtual User modify(Comment &comment) = 0;
    virtual User remove(Comment &comment) = 0;

    virtual int bump(Comment &comment) = 0;
    virtual int sage(Comment &comment) = 0;
};

class DBComment;

class CommentService : ContestServiceInterface {
    DBComment &repository;
 public:
    User get(Comment &comment);
    User add(Comment &comment);
    User modify(Comment &comment);
    User remove(Comment &comment);

    int bump(Comment &comment);
    int sage(Comment &comment);
};
