#!/usr/bin/php
<?php $name  = $argv[1] ?>
<?php $class = ucfirst(strtolower($name))."Expression"; ?>

<?php ob_start(); ?>
#ifndef <?php echo strtoupper($name) ?>_H 
#define <?php echo strtoupper($name) ?>_H 

#include "function.h"

class <?php echo $class ?> : FunctionExpression
{
  public:
    <?php echo $class ?>();
    <?php echo $class ?>(const Expression* arg);  

    virtual Expression* derivative();
}; 

#endif // <?php echo strtoupper($name) ?>_H 
<?php $header = ob_get_contents(); ?>
<?php ob_end_clean(); ?>

<?php ob_start(); ?>
#include "<? echo strtolower($name) ?>.h"

<?php echo $class ?>::<?php echo $class ?>() {}

<?php echo $class ?>::<?php echo $class ?>(const Expression* arg) 
{
  this->name = "<?php echo $name ?>";

  this->args.push_back(arg);
}

Expression* <?php echo $class ?>::derivative()
{
  // TU OBLICZAMY POCHODNA FUNKCJI
}

<?php $source = ob_get_contents(); ?>
<?php ob_end_clean(); ?>

<?php file_put_contents(strtolower($name).".h", $header); ?>
<?php file_put_contents(strtolower($name).".cc", $source); ?>