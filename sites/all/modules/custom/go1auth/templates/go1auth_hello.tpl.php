<div class="userLogin pull-right text-right"> <user-header class="ng-isolate-scope">
<div class="user-logged ng-scope" ng-controller="dropdownController" aria-hidden="false">
  <div class="dropdown">
    <button class="btn dropdown-toggle" type="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
      <span class="ng-binding"><?php print $firstname; ?> <?php print $lastname; ?></span>
      <span><i class="fa fa-angle-down"></i></span>
    </button>
    <ul class="toggleView dropdown-menu">
      <li><?php print $logout; ?></li>
    </ul>
  </div>
</div>
</user-header>