#!/usr/bin/php
<?php $name  = $argv[1] ?>
<?php $class = ucfirst(strtolower($name))."Expression"; ?>

<?php ob_start(); ?>
#ifndef <?php echo strtoupper($name) ?>_H 
#define <?php echo strtoupper($name) ?>_H 

#include "../expression.h"

class <?php echo $class ?> : Expression
{
  public:
    <?php echo $class ?>();
    <?php echo $class ?>(const Expression* arg0, const Expression* arg1);  

    virtual std::string toString();
    virtual Expression* derivative();
}; 

#endif // <?php echo strtoupper($name) ?>_H 
<?php $header = ob_get_contents(); ?>
<?php ob_end_clean(); ?>

<?php ob_start(); ?>
#include "<? echo strtolower($name) ?>.h"

<?php echo $class ?>::<?php echo $class ?>() {}

<?php echo $class ?>::<?php echo $class ?>(const Expression* arg0, const Expression* arg1) 
{
  this->args.push_back(arg0);
  this->args.push_back(arg1);
}

Expression* <?php echo $class ?>::derivative()
{
  // TU OBLICZAMY POCHODNA FUNKCJI
}

std::string <?php echo $class ?>::toString()
{
  // LUDZKA POSTAĆ WYRAŻENIA
}

<?php $source = ob_get_contents(); ?>
<?php ob_end_clean(); ?>

<?php file_put_contents(strtolower($name).".h", $header); ?>
<?php file_put_contents(strtolower($name).".cc", $source); ?>