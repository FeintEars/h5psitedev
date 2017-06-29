if (typeof H5PEditor !== 'undefined') {
  H5PEditor.LibrarySelector.prototype.appendTo = function ($element) {
    this.$parent = $element;
  };
}
