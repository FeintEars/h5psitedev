<div class="pull-right">
  <div class="buttons pull-right">
    <button data-toggle="collapse" data-target="#<?php print $block_html_id; ?>"><?php print t('Log in'); ?></button>
    <?php print t('Or'); ?>
    <button data-toggle="collapse" data-target="#<?php print $block_html_id; ?>-new"><?php print t('Sign in'); ?></button>
  </div>

  <div class="forms-container">
    <div id="<?php print $block_html_id; ?>" class="collapse <?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
    <?php if ($block->subject): ?>
      <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
    <?php endif;?>
      <?php print render($title_suffix); ?>
      <div class="content"<?php print $content_attributes; ?>>
        <?php print $content ?>
      </div>
    </div>

    <div id="<?php print $block_html_id; ?>-new" class="collapse <?php print $classes; ?>"<?php print $attributes; ?>>
      <?php print $content2; ?>
    </div>
  </div>

</div>